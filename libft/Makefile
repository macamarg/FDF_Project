# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 11:43:48 by macamarg          #+#    #+#              #
#    Updated: 2024/10/02 13:45:40 by macamarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_atoi.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_calloc.c\
	ft_bzero.c\
	ft_memset.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strrchr.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strdup.c\
	ft_strncmp.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\
	ft_printf.c\
	ft_string.c\
	ft_number.c\
	ft_pointer.c\
	ft_hexa.c\
	ft_itoa_base.c\
	ft_itoa_pointer.c\
	ft_putchar_count.c\
	ft_stacknew.c\
	exit_error.c\
	ft_atol.c\
	ft_atoi_base.c\
	get_next_line.c\
	get_next_line_utils.c\

CC = cc

FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

OBJ := $(SRC:%.c=%.o)

BONUS_OBJ := $(BONUS_SRC:%.c=%.o)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
