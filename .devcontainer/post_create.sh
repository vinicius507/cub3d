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
install_precommit_norminette_hook
create_compile_commands