/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:47:25 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/21 15:47:26 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = ft_stack_len(*stack);
	if (!(*stack) || !stack || len == 1)
		return ;
	last_node = ft_last_node(*stack);
	last_node->next = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}