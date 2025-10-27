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

int		is_unique_value(t_pslist *item, char *value)
{
	if (!item)
		return (0);
	return (item->value != ft_atoi(value));
}


void	find_integer(char *arg, int i, int *em, size_t *s, size_t *e, t_list **l)
{
	char	*tmp_value;

	if (ft_isdigit(arg[i]) || ((arg[i] == '-') && ft_isdigit(arg[i + 1])))
	{
		if (*em == 0)
		{
			*s = i;
			*em = 1;
		}
		if (*em == 1 && (arg[i + 1] == ' ' || arg[i + 1] == '\0'))
		{
			*e = i;
			tmp_value = ft_substr(arg, *s, (*e - *s) + 1);
			if (lst_is_true(tmp_value, *l, is_unique_value))
			{
				printf("TEST\n");
			}
			printf("{%s}\n", tmp_value);
			free(tmp_value);
		}
	}
	else if (arg[i] == ' ')
		*em = 0;
	// else
	// ft_lstclear(&(*list), free);
}

t_list		*extract_integers(int argc, char **argv)
{
	int		i;
	int		j;
	int		empty;
	size_t	start;
	size_t	end;
	t_list	*list;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		empty = 0;
		start = 0;
		end = 0;
		while (argv[i][j++] != '\0')
			find_integer(argv[i], (j - 1), &empty, &start, &end, &list);
	}
	return ((t_list *)(void *)0);
}
