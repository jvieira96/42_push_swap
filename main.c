/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:20:43 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/20 13:20:46 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !(argv[1][0])))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1]);
	// if (argv == NULL)
	// 	ft_error_free(&a);
	ft_init_stack(&a, argv, argc);
	if (argc == 2)
		ft_free_arg(argv);
	if (!ft_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a);
		else if (ft_stack_len(a) == 3)
			ft_tiny_sort(&a);
		else
			ft_push_swap(&a, &b);
	}
	ft_free_stack(&a);
}
