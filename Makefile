# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 14:58:21 by fflamion          #+#    #+#              #
#    Updated: 2024/09/17 11:03:04 by fflamion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -Iminilibx -Ilibft -g
LDFLAGS = -Lminilibx -Llibft -lmlx_Linux -lXext -lX11 -lm -lbsd -lft

LIBFT_TARGET = libft/libft.a
MLX_TARGET = minilibx/libmlx.a

SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRC_FILES:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(MLX_TARGET) $(LIBFT_TARGET)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX_TARGET):
	@make -C minilibx

$(LIBFT_TARGET):
	@make -C libft

clean:
	@make clean -C minilibx
	@make clean -C libft
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re