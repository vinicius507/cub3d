ARG VARIANT=20.04
FROM mcr.microsoft.com/devcontainers/base:ubuntu-${VARIANT}

RUN apt update \
    && apt install -y \
       clang-12 bear valgrind gcc libxext-dev libbsd-dev libx11-6 make

RUN ln -s /usr/bin/clang-12 /usr/local/bin/cc
RUN git clone https://github.com/42Paris/minilibx-linux /tmp/libmlx \
 && make -C /tmp/libmlx \
 && mv /tmp/libmlx/libmlx.a /usr/local/lib/libmlx.a \
 && mv /tmp/libmlx/mlx.h /usr/local/include/mlx.h