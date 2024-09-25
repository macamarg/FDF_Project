/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:45:18 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/23 09:45:18 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
/*
typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

void	func(void *lst_content)
{
	printf("%s\n", (char *)lst_content);
	return((void )lst_content);
}

void del(void *content)
{
	free(content);
}

t_list	*ft_lstnew(void *content);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstclear(t_list **lst, void (*del)(void*));
*/

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	t_list	*iter;

	if (l == NULL || !f)
		return (NULL);
	temp = ft_lstnew((*f)(l->content));
	new_lst = temp;
	iter = l->next;
	while (iter != NULL)
	{
		temp = ft_lstnew((*f)(iter->content));
		if (!temp)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
		iter = iter->next;
	}
	return (new_lst);
}
/*
int	main()
{
	t_list *one;
	t_list *two;
	t_list *new_lst;
	t_list *iter;

	one = (t_list *)malloc(sizeof(t_list));
	two = (t_list *)malloc(sizeof(t_list));
	new_lst = (t_list *)malloc(sizeof(t_list));

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
	new_lst = ft_lstmap(one, func, del);
	iter = new_lst;
	printf("\n\n");
	ft_lstmap(iter, &func, &del);
	printf("\n\n");
	while (iter != NULL)
	{
		printf("%p %p %s\n", iter->next, iter, (char *)iter->content);
		iter = iter->next;
	}
}*/
