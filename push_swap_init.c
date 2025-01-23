/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:26:15 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/22 15:26:17 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	-sets the index to each node in b
	the index is the node position in the list
	-this function also sets the bool value based in 
	if the node is above or bellow the middle of the list
 */

void	ft_set_index(t_stack_node *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (stack == NULL)
		return ;
	middle = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

/* 
	target node -> this function assigns to each node of b a node in b
		the target node is the smallest bigger
		if theres no bigger is simply the smallest
 */

void	ft_set_target_node(t_stack_node *a, t_stack_node *b)
{
	long			best_index;
	t_stack_node	*a_copy;
	t_stack_node	*target_node;

	while (b)
	{
		best_index = LONG_MAX;
		a_copy = a;
		while (a_copy)
		{
			if (a_copy->nbr > b->nbr && a_copy->nbr < best_index)
			{
				target_node = a_copy;
				best_index = a_copy->nbr;
			}
			a_copy = a_copy->next;
		}
		if (best_index == LONG_MAX)
			b->target_node = ft_find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/*
	sets the price to push the node b to a
	if the node is above median the price is the index value 
	if the node is bellow median the price is the len of the stack - node index
 */

void	ft_set_prince(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (b)
	{
		if (b->above_median)
			b->push_price = b->index;
		if (!(b->above_median))
			b->push_price = len_b - (b->index);
		if (b->target_node->above_median)
			b->push_price += b->target_node->index;
		if (!(b->target_node->above_median))
			b->push_price += len_a - (b->target_node->index);
		b = b->next;
	}
}

/*
	goes trough the b stack and finds the node that as the lowest push price
 */

void	ft_set_cheapest(t_stack_node *b)
{
	long			cheapest;
	t_stack_node	*cheapest_node;

	cheapest = LONG_MAX;
	while (b)
	{
		if (b->push_price < cheapest)
		{
			cheapest = b->push_price;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

/*
	sets every parameter of the node that we need to sort
	everytime we do a operation everything is refreshed
 */

void	ft_init_nodes(t_stack_node *a, t_stack_node *b)
{
	ft_set_index(a);
	ft_set_index(b);
	ft_set_target_node(a, b);
	ft_set_prince(a, b);
	ft_set_cheapest(b);
}
