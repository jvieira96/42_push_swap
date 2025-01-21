/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:02:41 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/20 13:02:42 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_stack_node
{
	int	nbr;
	struct s_stack_node	*next;
	struct s_stack_node *prev;
}	t_stack_node;

/*--------------------INIT STACK--------------------*/
// init_stack.c
long ft_atol(char *str);
void ft_init_stack(t_stack_node **stack, char **argv);

// errors.c
void ft_free_stack(t_stack_node **stack);
int ft_error_repetition(t_stack_node *stack, int nbr);
int	ft_error_syntax(char *str);
void ft_error_free(t_stack_node **stack);

/*--------------------SPLIT FUNCTIONS--------------------*/
// ft_split.c
int	ft_count_words(char *str);
char *ft_strncpy(char *s1, char *s2, int n);
void	ft_copy(char **strings, char *str);
char	**ft_split(char *str);

/*--------------------UTILS--------------------*/
// stack_utils.c
t_stack_node	*ft_last_node(t_stack_node *stack);
void	ft_append_node(t_stack_node **stack, int nbr);
int	ft_stack_len(t_stack_node *stack);

/*--------------------OPERATIONS--------------------*/
// swap.c
void	ft_swap(t_stack_node **head);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);

// push.c
void	ft_push(t_stack_node **src, t_stack_node **dest);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **b, t_stack_node **a);

// rotate.c
void	ft_rotate(t_stack_node **stack);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);

// reverse_rotate.c
void	ft_reverse_rotate(t_stack_node **stack);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);

/*--------------------SORTING--------------------*/
// tiny_sort.c
bool	ft_sorted(t_stack_node *stack);
t_stack_node	*ft_find_highest(t_stack_node *stack);
void	ft_tiny_sort(t_stack_node **a);

#endif