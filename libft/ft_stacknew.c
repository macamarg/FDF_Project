/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:15:43 by macamarg          #+#    #+#             */
/*   Updated: 2024/08/09 14:03:49 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->val = value;
	new->index_status = 0;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*iter;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	iter = *stack;
	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	iter->next = new;
	new->prev = iter;
}

t_stack	*ft_stacklast(t_stack **lst)
{
	t_stack	*iter;

	if (!lst)
		return (NULL);
	iter = *lst;
	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	return (iter);
}

int	ft_stacklen(t_stack **stack_a)
{
	t_stack	*iter;
	int		i;

	i = 0;
	if (!stack_a)
		return (0);
	iter = *stack_a;
	while (iter != NULL)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}
