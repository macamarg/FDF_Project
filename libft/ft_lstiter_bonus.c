/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:44:56 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/23 09:44:56 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
/*
typedef struct s_list
{
	void		*content;
	struct s_list	*next;
} t_list;

void	func(void *lst_content)
{
	printf("%s\n", (char *)lst_content);
}
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iter;

	iter = lst;
	while (iter != NULL)
	{
		(*f)(iter->content);
		iter = iter->next;
	}
}
/*
int	main(void)
{
	t_list *one;
	t_list *two;
	//t_list **pointer;
	t_list *iter;

	one = (t_list *)malloc(sizeof(t_list));
	two = (t_list *)malloc(sizeof(t_list));

	char *str = "Run to the hills";
	char *str2 = "run for your lives";
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
	ft_lstiter(one, func);
	printf("\n\ndepois\n");
	iter = one;
	//printf("%p %p %s\n", iter->next, iter, (char *)iter->content);
	while (iter != NULL)
	{
		printf("%p %p %s\n", iter->next, iter, (char *)iter->content);
		iter = iter->next;
	}
}
*/