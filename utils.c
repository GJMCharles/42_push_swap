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

int *fetch_from_stingle_string_arg(char *arg1, unsigned int *len)
{
	unsigned int	i;
	unsigned int	empty;
	unsigned int	x;
	int				start;
	int				end;

	i = 0;
	
	x = 0;
	start = 0;
	end = 0;
	empty = 0;
	while (arg1[i++] != '\0')
	{
		if (ft_isdigit(arg1[i - 1]) || \
			((arg1[i - 1] == '-') && ft_isdigit(arg1[i])))
		{
			if (empty == 0)
				start = (i - 1);
			if (arg1[i] == ' ' || arg1[i] == '\0')
			{
				end = i;
				printf("{%d}~ [%d]_[%d]\n", (end - start), start, end);
				empty = 0;
			}
		}
		else if (arg1[i - 1] == ' ')
			empty = 0;
		else
		{
			printf("%c", arg1[i - 1]);
			return ((int *)(void *)0);
		}
	}
	printf("...\n");
	*len = 1;
	return ((int *)(void *)0);
}

int	*fetch_from_multiple_args(int argc, char **argv, unsigned int *len)
{
	int				*tab;
	int				i;
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
		value = ft_atonb(argv[i]);
		if ((value < -2147483648) || (value > 2147483647))
		{
			free(tab);
			return ((int *)(void *)0);
		}
		tab[i - 1] = (int) value;
	}
	*len = i;
	return (tab);
}

int	*get_integer_tab(int argc, char **argv, unsigned int *len)
{	
	int				*tab;

	if (argc == 2)
		tab = fetch_from_stingle_string_arg(argv[1], &(*len));
	else
		tab = fetch_from_multiple_args(argc, argv, &(*len));
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
