/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:52 by macamarg          #+#    #+#             */
/*   Updated: 2024/08/09 11:47:58 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdlib.h>
#include <stdio.h>

typedef struct list
{
	struct list *next;
	void	*content;
}t_list;
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iter;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	iter = *lst;
	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	iter->next = new;
}
/*
int	main(void)
{
	t_list	*one;
	t_list	*two;
    t_list  *three;
	t_list	*iter;
	char	*str = "Run to the hills";
	char	*str2 = "run for your lives";
    char    *str3 = "Yeah!";
	
	one = (t_list *)malloc(sizeof(t_list));
	two = (t_list *)malloc(sizeof(t_list));
    three = (t_list *)malloc(sizeof(t_list));
	one->content = (void *)str;
	one->next = two;
	two->content = (void *)str2;
	two->next = NULL;
    three->content = (void *)str3;
    three->next = NULL;
	iter = one;
	while (iter != NULL)
	{
		printf("%p %p %s\n", iter->next, iter, (char *)iter->content);
		iter = iter->next;
	}
	ft_lstadd_back(&one, three);
    iter = one;
    while (iter != NULL)
	{
		printf("final result %p %p %s\n", iter->next, iter,
		 (char *)iter->content);
		iter = iter->next;
	}
}
*/
