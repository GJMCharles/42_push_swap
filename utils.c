/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:35:33 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/21 23:59:20 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_found(void)
{
	char	message[6];

	message[0] = 'E';
	message[1] = 'r';
	message[2] = 'r';
	message[3] = 'o';
	message[4] = 'r';
	message[5] = '\0';
	ft_putendl_fd(message, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

int	is_number(const char *str)
{
	int		i;

	i = 0;
	if ((str[i] == '-') && ft_isdigit(str[i + 1]))
		i += 1;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i += 1;
	}
	return (1);
}

int	*get_integer_tab(int argc, char **argv, unsigned int *len)
{
	int				i;
	int				*tab;
	long long int	value;

	tab = (int *)ft_calloc(sizeof(int), argc);
	if (!tab)
		return ((int *)(void *)0);
	i = 0;
	while (++i < argc)
	{
		if (!is_number(argv[i]))
		{
			free(tab);
			return ((int *)(void *)0);
		}
		value = ft_aton(argv[i]);
		if ((value < -2147483647) || (value > 2147483648))
		{
			free(tab);
			return ((int *)(void *)0);
		}
		tab[i - 1] = (int) value;
	}
	*len = i;
	return (tab);
}

int	is_distinct_tab(int *tab, unsigned int len)
{
	int				*test_tab;
	unsigned int	i;
	unsigned int	j;

	test_tab = (int *)ft_calloc(sizeof(int), len + 1);
	if (!test_tab)
		return (0);
	i = 0;
	while (i++ < (len - 1))
	{
		j = 0;
		while (j++ < (i - 1))
		{
			if (test_tab[j - 1] == tab[i - 1])
			{
				free(test_tab);
				return (0);
			}
		}
		test_tab[j - 1] = tab[i - 1];
	}
	free(test_tab);
	return (1);
}
