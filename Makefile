# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 12:35:24 by vgoncalv          #+#    #+#              #
#    Updated: 2023/01/14 17:20:29 by vgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
LIBFT_INCLUDES_DIR = ./$(LIBFT_DIR)/include ./$(LIBFT_DIR)

LIBMLX_FLAGS = -lXext -lmlx -lX11

LIBS_FLAGS = $(LIBFT_FLAGS) $(LIBMLX_FLAGS)
LIBS_INCLUDES = $(LIBFT_INCLUDES_DIR)
SRCS_DIR := ./src
vpath %.c $(SRCS_DIR)
SRCS = main.c error.c parse_args.c config.c

OBJS = $(addprefix $(BUILD_DIR)/,$(SRCS:%.c=%.o))
BUILD_DIR = ./build

INCLUDES_DIR = $(LIBS_INCLUDES)
INCLUDES = $(addprefix -I,$(INCLUDES_DIR))

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ $(LIBS_FLAGS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(BUILD_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	$(RM) $(BUILD_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
