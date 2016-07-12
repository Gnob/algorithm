set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
set colorcolumn=110
let &path.="src/include,/usr/include/AL,"
let g:ycm_global_ycm_extra_conf = "~/.vim/.ycm_extra_conf.py"

nnoremap <F4> :!time ./"%:t:r".out < "%:t:r"-in.txt<cr>
nnoremap <F5> :!./"%:t:r".out < "%:t:r"-in.txt<cr>
nnoremap <F6> :!g++ "%:t" -o "%:t:r".out -std=c++11<cr>

" generate random number at end of current line 
function! s:Rand(max)
y a         
redir @b    
ruby << EOF
  rmax = VIM::evaluate("a:max")
  rmax = nil if rmax == ""
  printf rand(rmax).to_s
EOF
redir END 
let @a = strpart(@a, 0, strlen(@a) - 1)
let @b = strpart(@b, 1, strlen(@b) - 1)
let @c = @a . @b
.s/.*/\=@c/g
endfunction
command! -nargs=? Rand :call <SID>Rand(<q-args>)
"nmap <F6> :Rand <CR>
nmap <F8> :Rand 32<CR>
" nmap <F8> :Rand 100<CR>
