# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 11:08:14 by macamarg          #+#    #+#              #
#    Updated: 2024/10/02 13:45:34 by macamarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf_main.c\
	fdf_map.c\
	fdf_map_covert.c\
	fdf_hooks.c\
	fdf_color.c\
	fdf_draw.c\
	fdf_free_map.c\

SRC_BONUS = 

LIBFT_DIR = ./libft

WFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

FLAGS = -lmlx_Linux -lX11 -lXext -lm

LIB =  -L../../minilibx-linux

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