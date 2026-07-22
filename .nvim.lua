vim.keymap.set("n", "<F5>", ":w<CR>:!make && ./game<CR>", { noremap = true, silent = false })
vim.keymap.set("n", "<F6>", ":w<CR>:!make debug && ./game<CR>", { noremap = true, silent = false })
