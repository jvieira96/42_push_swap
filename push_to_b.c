/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovieira <joaovieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:55:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/24 19:16:29 by joaovieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pivot(t_stack_node *stack)
{
	t_stack_node	*smallest_node;
	t_stack_node	*biggest_node;
	int				pivot;

	if (stack == NULL)
		return (0);
	smallest_node = ft_find_smallest(stack);
	biggest_node = ft_find_highest(stack);
	pivot = (smallest_node->nbr + biggest_node->nbr) / 2;
	return (pivot);
}

void	ft_part_stack(t_stack_node **a, t_stack_node **b)
{
	int	len;
	int	pivot;

	if (a == NULL || b == NULL)
		return ;
	len = ft_stack_len(*a);
	pivot = ft_pivot(*a);
	if (len == 3)
		return ;
	while (len > 3)
	{
		if ((*a)->nbr <= pivot)
			pb(b, a);
		else
			ra(a);
		len--;
	}
	ft_part_stack(a, b);
}
