/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:20:52 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/20 14:20:53 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * sign);
}

void	ft_init_stack(t_stack_node **stack, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_error_syntax(argv[i]))
		{
			printf("1");
			ft_error_free(stack);
		}
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			printf("2");
			ft_error_free(stack);
		}
		if (ft_error_repetition(*stack, (int)nbr))
		{
			printf("3");
			ft_error_free(stack);
		}
		ft_append_node(stack, (int)nbr);
		i++;
	}
}
