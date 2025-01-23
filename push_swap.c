/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:28:11 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/22 14:28:12 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_both(t_stack_node **a,
										t_stack_node **b,
										t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b);
	ft_set_index(*a);
	ft_set_index(*b);
}

void	ft_reverse_rotate_both(t_stack_node **a,
												t_stack_node **b,
												t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b);
	ft_set_index(*a);
	ft_set_index(*b);
}

void	ft_finish_rotation(t_stack_node **stack,
												t_stack_node *cheapest,
												char name)
{
	while (*stack != cheapest)
	{
		if (name == 'a')
		{
			if (cheapest->above_median)
				ra(stack);
			else
				rra(stack);
		}
		if (name == 'b')
		{
			if (cheapest->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	ft_move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = ft_cheapest_node(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		ft_rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		ft_reverse_rotate_both(a, b, cheapest_node);
	ft_finish_rotation(a, cheapest_node->target_node, 'a');
	ft_finish_rotation(b, cheapest_node, 'b');
	pa(a, b);
}

void	ft_push_swap(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	t_stack_node	*smallest;

	len_a = ft_stack_len(*a);
	while (len_a > 3)
	{
		pb(b, a);
		len_a--;
	}
	ft_tiny_sort(a);
	while (*b)
	{
		ft_init_nodes(*a, *b);
		ft_move_nodes(a, b);
	}
	ft_set_index(*a);
	smallest = ft_find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
