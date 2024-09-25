/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:43 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/23 09:44:48 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>
/*
typedef struct list
{
	struct list	*next;
	void		*content;
}t_list;

char	*ft_strdup(const char *s);

int	ft_strlen(const char *s);

void del(void *content)
{
	free(content);
}
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*iter;
	t_list	*next;

	iter = *lst;
	while (iter != NULL)
	{
		next = iter->next;
		del(iter->content);
		iter->next = NULL;
		iter->content = NULL;
		free (iter);
		iter = next;
	}
	free (iter);
	*lst = NULL;
}
/*
int	main(void)
{
	t_list *one;
	t_list *two;
	t_list **pointer;
	t_list *iter;

	one = (t_list *)malloc(sizeof(t_list));
	two = (t_list *)malloc(sizeof(t_list));
	pointer = (t_list **)malloc(sizeof(t_list *));

	char *str = ft_strdup("Run to the hills");
	char *str2 = ft_strdup("run for your lives");
	one->content = (void *)str;
	one->next = two;
	two->content = (void *)str2;
	two->next = NULL;
	iter = one;
	printf("antes list\n");
	while (iter != NULL)
	{
		printf("%p %p %s\n", iter->next, iter, (char *)iter->content);
		iter = iter->next;
	}
	printf("\n\n");
	*pointer = one;
	ft_lstclear(pointer, &del);
	printf("\n\ndepois\n");
	printf("%p %p %s\n", one->next, one, (char *)one->content);
	printf("%p %p %s\n", two->next, two, (char *)two->content);
}*/