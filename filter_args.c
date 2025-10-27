/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 03:20:06 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/27 03:20:18 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_integer_tab(int argc, char **argv, unsigned int *len)
{	
	int				*tab;

	if (argc == 2)
		tab = fetch_from_single_arg(argv[1], &(*len));
	else
		tab = fetch_from_multiple_args(argc, argv, &(*len));
	return (tab);
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

int *fetch_from_single_arg(char *arg1, unsigned int *len)
{
	int	i;
	int empty;
	int	start;
	int end;

	i = 0;
	empty = 0;
	start = 0;
	end = 0;
	while (arg1[i++] != '\0')
	{
		// fetch_from_single_arg_bis(arg1, i, start, end);
		if (ft_isdigit(arg1[i - 1]) || ((arg1[i - 1] == '-') && ft_isdigit(arg1[i])))
		{
			if (empty == 0)
			{
				start = (i - 1);
				empty = 1;
			}
			if (empty == 1 && (arg1[i] == ' ' || arg1[i] == '\0'))
			{
				end = i;
				printf("Start [%d] | End [%d]\n", start, end);
			}			
		}
		else if (arg1[i - 1] == ' ')
			empty = 0;
		else
			return ((int *)(void *)0);
	}
	*len = 1;
	return ((int *)(void *)0);
}

// void	*fetch_from_single_arg_bis(char *arg1, int i, int start, int end)
// {
// 	// int	empty;

// 	// empty = 0;
// }
