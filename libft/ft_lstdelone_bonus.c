/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:38 by macamarg          #+#    #+#             */
/*   Updated: 2024/08/09 11:48:27 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <stdlib.h>

typedef	struct list
{
	struct	list *next;
	void	*content;
}t_list;

*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del && lst)
		del(lst->content);
	free(lst);
	lst = NULL;
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
    three->content = (void *)str3;
    three->next = NULL;
    two->next = three;
	iter = one;
	while (iter != NULL)
	{
		printf("%p %p %s\n", iter->next, iter, (char *)iter->content);
		iter = iter->next;
	}
	ft_lstdelone(one, *del);
    iter = one;
    while (iter != NULL)
	{
		printf("final result %p %p %s\n", iter->next, iter,
		 (char *)iter->content);
		iter = iter->next;
	}
    printf("three %p %p %s\n", three->next, three,
	 (char *)three->content);
}
*/
