vim.keymap.set("n", "<F5>", ":w<CR>:make! OBJS=\"src/*.cpp\" && ./game<CR>", { noremap = true, silent = true })
vim.keymap.set("n", "<F6>", ":make! OBJS=\"src/*.cpp\" BUILD_MODE=DEBUG && ./game<CR>", { noremap = true, silent = true })
