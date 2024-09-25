/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:27:38 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/23 09:45:15 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	struct	s_list *next;
	void	*content;
}t_list;

void	ft_lstadd_front(t_list **lst, t_list *new);
{
	new->next = *lst;
	*lst = new;
}
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*iter;

	if (!lst)
		return (NULL);
	iter = lst;
	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	return (iter);
}
/*
int	main(void)
{
	t_list	*new;
	t_list	*prev;
	t_list	*iter;
	char	*str = "Run to the hills";
	char	*str2 = "run for your lives";
	
	new = (t_list *)malloc(sizeof(t_list));
	prev = (t_list *)malloc(sizeof(t_list));
	new->content = (void *)str;
	new->next = NULL;
	prev->content = (void *)str2;
	prev->next = NULL;
	iter = new;
	printf("%p %p %s\n", new->next, new, (char *)new->content);
	printf("%p %p %s\n", prev->next, prev, (char *)prev->content);
	ft_lstadd_front(&prev, new);
	iter = new;
	printf("\nbefore last\n\n");
	while (iter != NULL)
	{
		printf("%p %p %s\n", iter->next, iter, (char *)iter->content);
		iter = iter->next;
	}
	iter = new;
	iter = ft_lstlast(new);
	printf("\nfinal\n\n");
    while (iter != NULL)
	{
		printf("%p %p %s\n", iter->next, iter, (char *)iter->content);
		iter = iter->next;
	}
}*/