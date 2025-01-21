/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:26:34 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/21 17:26:38 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*ft_find_highest(t_stack_node *stack)
{
	t_stack_node	*highest_node;
	int				highest;

	if (!stack)
		return (NULL);
	highest = -2147483648;
	while (stack)
	{
		if (stack->nbr > highest)
		{
			highest = stack->nbr;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	ft_tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = ft_find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}