# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 12:35:24 by vgoncalv          #+#    #+#              #
#    Updated: 2022/11/29 12:42:37 by vgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft-cproject

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L./libft -lft
LIBFT_INCLUDES_DIR = ./libft/include ./libft

SRCS_DIR := ./src
vpath %.c $(SRCS_DIR)
SRCS = main.c

OBJS = $(addprefix $(BUILD_DIR)/,$(SRCS:%.c=%.o)) 
BUILD_DIR = ./build

INCLUDES_DIR = $(LIBFT_INCLUDES_DIR) $(SRCS_DIR)
INCLUDES = $(addprefix -I,$(INCLUDES_DIR))

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ $(LIBFT_FLAGS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(OBJDIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	$(RM) -r $(BUILD_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re so
