/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:58:37 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 10:58:37 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int				val;
	int				index;
	int				index_status;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strlen(const char *s);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_atoi(const char *nptr);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			*ft_calloc(size_t nelem, size_t elsize);
void			*ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
int				ft_lstsize(t_list *lst);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));
int				exit_error(char *error_msg, int ret);
int				exit_error_free(char *error_msg, int ret, void *freeable);
void			error_free_array(char *msg, int ret, void **freeble, int i);

//printf

int				ft_printf(const char *input, ...);
int				ft_string(char *str);
int				ft_number(int nbr);
int				ft_pointer(void *pointer);
int				ft_hexa(unsigned int hex, char c);
char			*ft_itoa_base(unsigned long long int num, char *base);
char			*ft_itoa_pointer(unsigned long long int num, char *base);
int				ft_putchar_count(char c);
unsigned int	ft_unsigend_number(unsigned int nbr);

//push swap
t_stack			*ft_stacknew(int value);
void			ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack			*ft_stacklast(t_stack **lst);
int				ft_stacklen(t_stack **stack_a);
long			ft_atol(const char *nptr);

#endif
