# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 16:39:33 by rtavabil          #+#    #+#              #
#    Updated: 2024/01/24 16:41:08 by rtavabil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

SRC :=  main.c strings.c init.c error.c render.c \
		complex_math.c ft_atof.c burning_ship.c \
		map.c julia.c init_julia.c init_ship.c
OBJ := $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

INC			= -I ./minilibx-linux/

OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC) -g

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(MLX):
	@make -sC $(MLX_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(INC) -lXext -lX11 -lm

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
