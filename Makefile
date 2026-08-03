CXX      ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -O2 -Iinclude
LDFLAGS   = $(shell pkg-config --libs raylib) -lGL -lm -lpthread -ldl -lrt -lX11

SRC_DIR := src
OBJ_DIR := obj
SRCS    := $(wildcard $(SRC_DIR)/*.cpp)
OBJS    := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
TARGET  := build/game

.PHONY: all clean run debug

all: $(TARGET)

$(TARGET): $(OBJS) | $(dir $(TARGET))
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(dir $(TARGET)):
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)

debug: CXXFLAGS += -g -O0 -DDEBUG
debug: all

clean:
	rm -rf $(OBJ_DIR) build
