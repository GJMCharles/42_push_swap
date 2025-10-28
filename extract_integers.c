/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_integers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 04:25:44 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/27 04:25:56 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_argv1(int *j, int *test, size_t *start)
{
	if (*test == 0)
	{
		*start = (*j - 1);
		*test = 1;
	}
}

void	parse_argv2(size_t end, size_t *start, const char *arg, t_list **list)
{
	char	*data;

	data = ft_substr(arg, *start, (end - *start) + 1);
	if (!is_valid_integer(data) || !can_append_list(data, &(*list)))
		return (free(data), ft_lstclear(&(*list), free));
	free(data);
}

int	test_argv(const char *arg, t_list **list)
{
	int		j;
	size_t	start;
	size_t	end;
	int		test;

	j = 0;
	start = 0;
	end = 0;
	test = 0;
	while (arg[j++] != '\0')
	{
		if (ft_isdigit(arg[j - 1]) || \
			((arg[j - 1] == '-') && ft_isdigit(arg[j])))
		{
			parse_argv1(&j, &test, &start);
			if (test == 1 && (arg[j] == ' ' || arg[j] == '\0'))
				parse_argv2(end = (j - 1), &start, arg, &(*list));
		}
		else if (arg[j - 1] == ' ')
			test = 0;
		else
			return (ft_lstclear(&(*list), free), 0);
	}
	return (1);
}

t_list	*extract_integers(int argc, char **argv)
{
	int		i;
	t_list	*list;

	i = 0;
	list = (t_list *)((void *)0);
	while (++i < argc)
	{
		if (!test_argv(argv[i], &list))
			return ((t_list *)((void *)0));
	}
	return (list);
}
