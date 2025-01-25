/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:14:18 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/21 15:14:19 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->nbr = nbr;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = -1;
	new_node->above_median = false;
	new_node->push_price = 0;
	new_node->target_node = NULL;
	new_node->cheapest = false;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last_node = ft_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

t_stack_node	*ft_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*ft_find_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < smallest)
		{
			smallest_node = stack;
			smallest = stack->nbr;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

int	ft_stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack_node	*ft_cheapest_node(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/* void	ft_print_stacks(t_stack_node *a, t_stack_node *b)
{
	printf("------------------------------\n");
	printf("------------STACK A-----------\n");
	printf("------------------------------\n");
	if (!a)
		printf("STACK A IS EMPTY\n");
	else
	{
		while (a)
		{	printf("\n");
			printf("nbr          - %d\n", a->nbr);
			printf("index        - %d\n", a->index);
			printf("push price   - %d\n", a->push_price);
			printf("above median - %d\n", a->above_median);
			printf("cheapest     - %d\n", a->cheapest);
			if (a->target_node)
				printf("target node  - %d\n", a->target_node->nbr);
			else
				printf("target node  - NULL\n");
			a = a->next;
		}
	}
	printf("\n");
	printf("------------------------------\n");
	printf("------------STACK B-----------\n");
	printf("------------------------------\n");
	if (!b)
		printf("STACK B IS EMPTY\n");
	else
	{
		while (b)
		{	printf("\n");
			printf("nbr          - %d\n", b->nbr);
			printf("index        - %d\n", b->index);
			printf("push price   - %d\n", b->push_price);
			printf("above median - %d\n", b->above_median);
			printf("cheapest     - %d\n", b->cheapest);
			if (b->target_node)
				printf("target node  - %d\n", b->target_node->nbr);
			else
				printf("target node  - NULL\n");
			b = b->next;
		}
	}
} */