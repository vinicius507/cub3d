ARG VARIANT=20.04
FROM mcr.microsoft.com/devcontainers/base:ubuntu-${VARIANT}

RUN apt update \
    && apt install -y clang-12 bear valgrind

RUN ln -s /usr/bin/clang-12 /usr/local/bin/cc
