# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 11:08:14 by macamarg          #+#    #+#              #
#    Updated: 2024/09/17 12:23:57 by macamarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf_2024_09_16

SRC = fdf_main.c\
	get_map.c\
	fdf_hooks.c\
	fdf_drawmap.c\
	fdf_free_map.c\
	map_convert.c\

SRC_BONUS = 

LIBFT_DIR = ./libft

WFLAGS = -Wall -Wextra -Werror -g

FLAGS = -lmlx_Linux -lX11 -lXext -lm

LIB =  -L./minilibx-linux

LIBFT_A = ./libft/libft.a

CC = cc

.PHONY: all bonus clean fclean re valgrind
  
all: $(NAME)

$(NAME):$(SRC)
	make -C $(LIBFT_DIR) all
	$(CC) $(WFLAGS) $^ $(LIB) $(LIBFT_A) $(FLAGS) -o $@ 

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	
valgrind:
	valgrind --track-fds=yes --show-leak-kinds=all --leak-check=full $(NAME)

re: fclean all