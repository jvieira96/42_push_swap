/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:18:37 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/20 12:18:39 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] == 32)
			&& !(str[i] >= 9 && str[i] <= 13) && str[i])
				return (-1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i])
			words++;
		while (str[i] && !(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			i++;
	}
	return (words);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

void	ft_copy(char **strings, char *str)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		k = i;
		while (str[i] && !(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (i > k)
		{
			strings[j] = (char *)malloc(sizeof(char) * ((i - k) + 1));
			if (!strings[j])
				return ;
			ft_strncpy(strings[j], &str[k], i - k);
			j++;
		}
	}
	strings[j] = NULL;
}

char	**ft_split(char *str)
{
	char	**strings;

	if (ft_check_char(str) == -1)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (ft_count_words(str) + 1));
	if (!strings)
		return (NULL);
	ft_copy(strings, str);
	return (strings);
}
