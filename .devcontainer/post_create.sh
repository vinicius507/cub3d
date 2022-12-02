#!/usr/bin/env bash

install_precommit_norminette_hook() {
    pip install --upgrade pip
    pip install pre-commit norminette
    pre-commit install
}

create_compile_commands() {
    bear make
    make fclean
}

install_minilibx() {
 git clone https://github.com/42Paris/minilibx-linux /tmp/libmlx
 make -C /tmp/libmlx
 mv /tmp/libmlx/libmlx.a /usr/local/lib/libmlx.a
 mv /tmp/libmlx/mlx.h /usr/local/include/mlx.h
 mv man/man1/* /usr/local/man/man1
 mv man/man3/* /usr/local/man/man3
}

install_precommit_norminette_hook
install_minilibx
create_compile_commands