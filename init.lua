-- =====================================================
-- Opciones básicas
-- =====================================================

vim.g.mapleader = " "

vim.opt.number = true
vim.opt.relativenumber = true
vim.opt.mouse = "a"
vim.opt.clipboard = "unnamedplus"
vim.opt.termguicolors = true
vim.opt.updatetime = 300
vim.opt.background = "dark"

vim.cmd("colorscheme sorbet")
vim.cmd("highlight EndOfBuffer guibg=#000000 guifg=#000000")
vim.cmd("syntax on")

-- =====================================================
-- Bootstrap lazy.nvim
-- =====================================================

local lazypath = vim.fn.stdpath("data") .. "/site/pack/lazy/start/lazy.nvim"

if not vim.loop.fs_stat(lazypath) then
	vim.fn.system({
		"git",
		"clone",
		"https://github.com/folke/lazy.nvim.git",
		lazypath,
	})
end

vim.opt.rtp:prepend(lazypath)

-- =====================================================
-- Plugins
-- =====================================================

require("lazy").setup({

	{
		"nvim-treesitter/nvim-treesitter",
		lazy = false,
		build = ":TSUpdate",
		opts = {
			ensure_installed = { "c", "lua", "python" },
			highlight = {
				enable = true,
				additional_vim_regex_highlighting = true,
			},
		},
	},


	{
		"williamboman/mason.nvim",
		config = function()
			require("mason").setup()
		end,
	},

	{
		"williamboman/mason-lspconfig.nvim",
		dependencies = { "williamboman/mason.nvim" },
		config = function()
			require("mason-lspconfig").setup({
				ensure_installed = {
					"lua_ls",
					"pyright",
					"clangd",
				},
			})
		end,
	},

	{
		"neovim/nvim-lspconfig",
	},

	{
		"hrsh7th/nvim-cmp",
		dependencies = {
			"hrsh7th/cmp-nvim-lsp",
		},
		config = function()
			local cmp = require("cmp")
			cmp.setup({
				mapping = cmp.mapping.preset.insert({
					--["<Tab>"] = cmp.mapping.select_next_item(),
					--["<S-Tab>"] = cmp.mapping.select_prev_item(),
					["<CR>"] = cmp.mapping.confirm({ select = true }),
					["<Down>"] = cmp.mapping(function(fallback)
						if cmp.visible() then cmp.select_next_item()
						else fallback()
						end
					end, { "i", "s" }),
					["<Up>"] = cmp.mapping(function(fallback)
						if cmp.visible() then cmp.select_prev_item()
						else fallback()
						end
					end, { "i", "s" }),
				}),
				sources = {
					{ name = "nvim_lsp" },
				},
			})
		end,
	},

	{
		"nvim-tree/nvim-tree.lua",
		config = function()
			require("nvim-tree").setup({})
		end,
	},

	{
		"nvim-lualine/lualine.nvim",
		config = function()
			require("lualine").setup({})
		end,
	},

	{ "nvim-lua/plenary.nvim" },

	{
		"nvim-telescope/telescope.nvim",
		dependencies = { "nvim-lua/plenary.nvim" },
	},

})

-- =====================================================
-- LSP CONFIG
-- =====================================================

local lspconfig = require("lspconfig")
local capabilities = require("cmp_nvim_lsp").default_capabilities()

lspconfig.clangd.setup({ capabilities = capabilities })
lspconfig.pyright.setup({ capabilities = capabilities })

lspconfig.lua_ls.setup({
	capabilities = capabilities,
	settings = {
		Lua = {
			diagnostics = {
				globals = { "vim" },
			},
		},
	},
})

-- =====================================================
-- Diagnósticos
-- =====================================================

vim.diagnostic.config({
	virtual_text = true,
	signs = true,
	underline = true,
	update_in_insert = false,
	severity_sort = true,
})

-- =====================================================
-- Keybindings
-- =====================================================

local map = vim.keymap.set
local opts = { noremap = true, silent = true }

map("n", "<C-s>", ":w<CR>", opts)
map("i", "<C-s>", "<Esc>:w<CR>a", opts)

map("n", "<C-b>", ":NvimTreeToggle<CR>", opts)
map("n", "<C-p>", ":Telescope find_files<CR>", opts)
map("n", "<C-f>", ":Telescope live_grep<CR>", opts)

map("n", "gd", vim.lsp.buf.definition, opts)
map("n", "K", vim.lsp.buf.hover, opts)
map("n", "<leader>rn", vim.lsp.buf.rename, opts)
map("n", "<leader>ca", vim.lsp.buf.code_action, opts)

map("n", "<leader>f", function()
	vim.lsp.buf.format({ async = true })
end)

--vim.api.nvim_create_autocmd("BufWritePre", {
--	callback = function()
--		vim.lsp.buf.format({ async = false })
--	end,
--})

-- ===============================
-- Terminal inferior automática
-- ===============================
vim.api.nvim_create_autocmd("VimEnter", {
	callback = function()
		-- Abrir split horizontal abajo
		vim.cmd("botright split | resize 10 | terminal")
		-- Volver al editor (no dejar foco en la terminal)
		vim.cmd("wincmd p")
	end,
})
-- =====================================================
-- 42 Cursus: header automático + libft include
-- =====================================================
-- Construye una línea del header 42 a 80 columnas exactas
--[[
local function hline(left, right)
	local total_width = 80
	local len = #left + #right
	if len >= total_width then
		return left .. right
	end
	return left .. string.rep(" ", total_width - len) .. right
end ]]--
local function hline(left, right)
	local total = 80
	if #left < total - #right then
		left = left .. string.rep(" ", total - #right - #left)
	end
	return left .. right
end
-- Detecta si el archivo está dentro de un proyecto cuyo nombre empiece por un prefijo
local function is_in_project_with_prefix(filepath, prefix)
	for dir in filepath:gmatch("[^/]+") do
		if dir:match("^" .. prefix) then
			return true
		end
	end
	return false
end

vim.api.nvim_create_autocmd("BufNewFile", {
	pattern = { "*.c", "*.py" },
	callback = function()
		local filepath = vim.fn.expand("%:p")

		if not is_in_project_with_prefix(filepath, "42proyects") then
			return
		end
		local filename = vim.fn.expand("%:t")
		local user = "tide-oli"
		local mail = "marvin@42.fr"
		local date = os.date("%Y/%m/%d %H:%M:%S")

		local is_c = filename:match("%.c$")
--[[		local header = {

			"/* ************************************************************************** */",
			"/*                                                                            */",
			"/*                                                        :::      ::::::::   */",

			hline("/*   " .. filename, ":+:      :+:    :+:   */"),
			"/*                                                    +:+ +:+         +:+     */",

			hline("/*   By: " .. user .. " <" .. mail .. ">", "#+#  +:+       +#+        */"),
			"/*                                                +#+#+#+#+#+   +#+           */",

			hline("/*   Created: " .. date .. " by " .. user, "#+#    #+#             */"),

			hline("/*   Updated: " .. date .. " by " .. user, "###   ########.fr       */"),
			"/*                                                                            */",
			"/* ************************************************************************** */",

			"",

		}--]]
		local header = {
		"/* ************************************************************************** */",
		"/*                                                                            */",
		"/*                                                        :::      ::::::::   */",
		hline(
			string.format("/*   %-51s", filename),
			":+:      :+:    :+:   */"
		),
		"/*                                                    +:+ +:+         +:+     */",
		hline(
			string.format("/*   By: %-42s", user .. " <" .. mail .. ">"),
			"+#+  +:+       +#+        */"
		),
		"/*                                                +#+#+#+#+#+   +#+           */",
		hline(
			string.format("/*   Created: %s by %-17s", date, user),
			"#++    #+#             */"
		),
		hline(
			string.format("/*   Updated: %s by %-17s", date, user),
			"###   ########.fr       */"
		),
		"/*                                                                            */",
		"/* ************************************************************************** */",
		"",
		}
		vim.api.nvim_buf_set_lines(0, 0, 0, false, header)

		if is_c and is_in_project_with_prefix(filepath, "proyect0_libft") then
			vim.api.nvim_buf_set_lines(0, #header, #header, false, {
				'#include "libft.h"',
				"",
			})
		end
	end,
})
vim.api.nvim_create_autocmd("BufWritePre", {
	pattern = { "*.c", "*.h", "*.py" },
	callback = function()
		local buf = vim.api.nvim_get_current_buf()
		local lines = vim.api.nvim_buf_get_lines(buf, 0, 15, false)
		local user = "tide-oli"
		local date = os.date("%Y/%m/%d %H:%M:%S")

		for i, line in ipairs(lines) do
			if line:match("^/%*%s+Updated:") then
				local new_line = hline(
					string.format("/*   Updated: %s by %-17s", date, user),
					"###   ########.fr       */"
				)
				vim.api.nvim_buf_set_lines(buf, i - 1, i, false, { new_line })
				break
			end
		end
	end,
})
