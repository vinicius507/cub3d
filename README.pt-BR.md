# Template de projeto em C da 42
[![build](https://github.com/vinicius507/ft-cproject/actions/workflows/build.yaml/badge.svg)](https://github.com/vinicius507/ft-cproject/actions/workflows/build.yaml)

Esse é meu template para projetos em C da [42](https://42.fr/), com objetivo de
utilizá-lo em meus projetos.

> **Warning**
> 
> Esse projeto possui uma git subtree (veja [`git-subtree(1)`](https://manpages.debian.org/testing/git-man/git-subtree.1.en.html))
> da minha biblioteca `libft`.
> Se deseja utilizar para seus projetos da 42, veja [Usando sua libft](#usando-sua-libft)

## Features
- Hook da norminette usando pre-commit (graças ao [vcwild](https://github.com/vcwild))
- Workflow de `build` usando Github actions
- Configuração de um [Devcontainer](https://code.visualstudio.com/docs/devcontainers/containers) para desenvolvimento em um container

## Usando sua libft
Se você é um estudante da 42, você precisa utilizar sua própria `libft` em seus projetos.
Para fazê-lo, basta:

1. Clonar o repositório
2. Remover a git subtree `libft` usando `git rm libft`
3. Adicionar sua própria pasta `libft` na raiz do repositório

Se você deseja usar sua `libft` como uma git subtree:

```sh
git subtree add --prefix libft $LIBFT_REPO_URL main --squash
```
