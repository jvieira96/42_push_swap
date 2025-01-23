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

int	ft_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
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

/* when i have 3 nodes:
	If the 1st is the biggest, ra (biggest to bottom)
	If the 2nd is the biggest, rra (biggest to bottom)
	Now the biggest is at the bottom 
	If 1st is bigger than 2nd, sa
 */
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
