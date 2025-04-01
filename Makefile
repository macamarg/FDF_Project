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

SRC_DIR = ./src

BONUS_DIR = ./src_bonus

SRC = $(SRC_DIR)/fdf_main.c\
	$(SRC_DIR)/fdf_map.c\
	$(SRC_DIR)/fdf_map_covert.c\
	$(SRC_DIR)/fdf_hooks.c\
	$(SRC_DIR)/fdf_color.c\
	$(SRC_DIR)/fdf_draw.c\
	$(SRC_DIR)/fdf_free_map.c\
	$(SRC_DIR)/fdf_modify.c\

SRC_BONUS = $(BONUS_DIR)/fdf_main_bonus.c\
	$(BONUS_DIR)/fdf_map_bonus.c\
	$(BONUS_DIR)/fdf_map_covert_bonus.c\
	$(BONUS_DIR)/fdf_hooks_bonus.c\
	$(BONUS_DIR)/fdf_color_bonus.c\
	$(BONUS_DIR)/fdf_draw_bonus.c\
	$(BONUS_DIR)/fdf_free_map_bonus.c\
	$(BONUS_DIR)/fdf_modify_bonus.c\

LIBFT_DIR = ./libft

MINILIBX_DIR = ./minilibx-linux

WFLAGS = -Wall -Wextra -Werror -g 

FLAGS = -lmlx_Linux -lX11 -lXext -lm

LIB =  -L./minilibx-linux

LIBFT_A = ./libft/libft.a

CC = cc

.PHONY: all bonus clean fclean re valgrind
  
all: $(NAME)

$(NAME):$(SRC)
	@make -C $(LIBFT_DIR) all
	@make -C $(MINILIBX_DIR)
	@$(CC) $(WFLAGS) $^ $(LIB) $(LIBFT_A) $(FLAGS) -o $@
	@echo "Compilation finished! Executable '$(NAME)' is ready."

bonus: $(NAME_BONUS)

$(NAME_BONUS):$(SRC_BONUS)
	@make -C $(LIBFT_DIR) all
	@make -C $(MINILIBX_DIR)
	@$(CC) $(WFLAGS) $^ $(LIB) $(LIBFT_A) $(FLAGS) -o $@ 

clean:
	@make -C $(LIBFT_DIR) clean
	@echo "*.o were cleaned."

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "Executable '$(NAME)' was removed."
	
	
valgrind:
	valgrind --track-fds=yes --show-leak-kinds=all --leak-check=full ./$(NAME_BONUS) 42.fdf

re: fclean all