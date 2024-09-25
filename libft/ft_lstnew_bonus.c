/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:45:26 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/23 09:45:26 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>
/*
typedef struct s_list 
{
	void *content;
	struct s_list *next;
}t_list;
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int	main()
{
	char *str1 = "Run to the hills";
	char *str2 = "run for your lives";
	t_list *l;
	t_list *k;
	t_list *iter;
	
	l = ft_lstnew((void *)str1);
	k = ft_lstnew((void *)str2);
	l->next = k;
	iter = l;
	while (iter != NULL)
	{
		printf("%p %p %s\n", iter->next, iter, (char *)iter->content);
		iter = iter->next;
	}

}
*/