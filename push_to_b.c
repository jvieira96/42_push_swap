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

long	ft_pivot(t_stack_node *stack)
{
	t_stack_node	*smallest_node;
	t_stack_node	*biggest_node;
	long			pivot;

	if (stack == NULL)
		return (0);
	smallest_node = ft_find_smallest(stack);
	biggest_node = ft_find_highest(stack);
	pivot = ((long)smallest_node->nbr + (long)biggest_node->nbr) / 2;
	return (pivot);
}

void	ft_part_stack(t_stack_node **a, t_stack_node **b)
{
	int		len;
	long	pivot;

	if (a == NULL || b == NULL)
		return ;
	len = ft_stack_len(*a);
	pivot = ft_pivot(*a);
	if (len == 3)
		return ;
	while (len > 3)
	{
		if ((*a)->nbr <= pivot)
		{
			pb(b, a);
			len--;
			pivot = ft_pivot(*a);
		}
		else
			ra(a);
	}
}
