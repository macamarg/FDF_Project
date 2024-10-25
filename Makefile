# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 11:08:14 by macamarg          #+#    #+#              #
#    Updated: 2024/10/25 13:10:39 by macamarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

NAME_BONUS = fdf_bonus

SRC = fdf_main.c\
	fdf_map.c\
	fdf_map_covert.c\
	fdf_hooks.c\
	fdf_color.c\
	fdf_draw.c\
	fdf_free_map.c\
	fdf_modify.c\

SRC_BONUS = fdf_main_bonus.c\
	fdf_map_bonus.c\
	fdf_map_covert_bonus.c\
	fdf_hooks_bonus.c\
	fdf_color_bonus.c\
	fdf_draw_bonus.c\
	fdf_free_map_bonus.c\
	fdf_modify_bonus.c\

LIBFT_DIR = ./libft

MINILIBX_DIR = ./minilibx-linux

WFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

FLAGS = -lmlx_Linux -lX11 -lXext -lm

LIB =  -L./minilibx-linux

LIBFT_A = ./libft/libft.a

CC = cc

.PHONY: all bonus clean fclean re valgrind
  
all: $(NAME)

$(NAME):$(SRC)
	make -C $(LIBFT_DIR) all
	make -C $(MINILIBX_DIR)
	$(CC) $(WFLAGS) $^ $(LIB) $(LIBFT_A) $(FLAGS) -o $@ 

bonus: $(NAME_BONUS)

$(NAME_BONUS):$(SRC_BONUS)
	make -C $(LIBFT_DIR) all
	make -C $(MINILIBX_DIR)
	$(CC) $(WFLAGS) $^ $(LIB) $(LIBFT_A) $(FLAGS) -o $@ 

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MINILIBX_DIR) fclean
	
valgrind:
	valgrind --track-fds=yes --show-leak-kinds=all --leak-check=full $(NAME)

re: fclean all