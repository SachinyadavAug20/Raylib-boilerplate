vim.keymap.set("n", "<F5>", ":w<CR>:!make && ./build/game<CR>", { noremap = true, silent = false })
vim.keymap.set("n", "<F6>", ":w<CR>:!make debug && ./build/game<CR>", { noremap = true, silent = false })
