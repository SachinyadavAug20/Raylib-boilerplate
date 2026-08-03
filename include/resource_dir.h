// ----------------------------------------------------------------------------
// resource_dir.h
//
// Utility to locate the game's assets folder at runtime, regardless of the
// working directory the binary is launched from. This is a common pain point
// when building into a subdirectory (e.g. build/) or running from an IDE.
//
// Adapted from the raylib-quickstart template (zlib/libpng license).
// ----------------------------------------------------------------------------
#pragma once

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#if defined(_WIN32)
    #include <direct.h>
    #define SEP "\\"
#else
    #include <unistd.h>
    #define SEP "/"
#endif

#define MAX_DIR_LEN 2048

// Attempt to switch the process working directory to one that contains the
// given folder name (e.g. "resources"). The folder is looked for in the
// current directory, the binary's directory, and up to 3 levels above it.
static inline int SearchAndSetResourceDir(const char* folderName) {
    char buffer[MAX_DIR_LEN] = { 0 };
    strcpy(buffer, folderName);

    // 1) Working directory
    struct stat st {};
    if (stat(buffer, &st) == 0 && S_ISDIR(st.st_mode)) return 1;

    // 2) Executable directory
    #if defined(_WIN32)
        GetModuleFileNameA(NULL, buffer, MAX_DIR_LEN);
        char* slash = strrchr(buffer, '\\');
        if (slash) {
            *slash = '\0';
            strcat(buffer, "\\" );
            strcat(buffer, folderName);
        }
    #else
        ssize_t len = readlink("/proc/self/exe", buffer, MAX_DIR_LEN);
        if (len > 0) {
            buffer[len] = '\0';
            char* slash = strrchr(buffer, '/');
            if (slash) {
                *slash = '\0';
                strcat(buffer, "/");
                strcat(buffer, folderName);
            }
        }
    #endif
    if (stat(buffer, &st) == 0 && S_ISDIR(st.st_mode)) return chdir(buffer) == 0;

    // 3) Parent traversal (up to 3 levels)
    char parent[MAX_DIR_LEN] = "..";
    for (int level = 0; level < 3; level++) {
        snprintf(buffer, MAX_DIR_LEN, "%s%s%s", parent, SEP, folderName);
        if (stat(buffer, &st) == 0 && S_ISDIR(st.st_mode)) return chdir(buffer) == 0;
        strcat(parent, SEP "..");
    }

    return 0;
}
