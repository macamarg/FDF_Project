/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:14 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/23 09:45:36 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdlib.h>
#include <stdio.h>

typedef struct list
{
	struct	list *next;
	void	*content;
}t_list;
*/

int	ft_lstsize(t_list *lst)
{
	t_list	*iter;
	int		i;

	i = 0;
	iter = lst;
	while (iter != NULL)
	{
		i++;
		iter = iter->next;
	}
	return (i);
}
/*
void	ft_lstadd_front(t_list **lst, t_list *new);

int	main(void)
{
	t_list	*new;
	t_list	*prev;
	t_list	*iter;
	char	*str = "Run to the hills";
	char	*str2 = "run for your lives";
	int	i;

	new = (t_list *)malloc(sizeof(t_list *));
	prev = (t_list *)malloc(sizeof(t_list *));
	new->content = (void *)str;
	new->next = NULL;
	prev->content = (void *)str2;
	prev->next = NULL;
	iter = new;
	while (iter != NULL)
	{
		printf("%p %p %s\n", iter->next, iter, (char *)iter->content);
		iter = iter->next;
	}
	ft_lstadd_front(&prev, new);
	iter = new;
	while (iter != NULL)
	{
		printf("%p %p %s\n", iter->next, iter, (char *)iter->content);
		iter = iter->next;
	}
	i = ft_lstsize(new);
	printf("%i\n", i);
}*/