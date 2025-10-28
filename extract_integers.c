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

int	can_append_list(const char *str, t_list **list)
{
	int			value;
	t_list		*tmp;
	t_list		*list_item;

	value = ft_atonb(str);
	tmp = *list;
	while (tmp)
	{
		if (((t_pslist *)tmp->content)->value == value)
			return (0);
		tmp = tmp->next;
	}
	list_item = create_list_item(value);
	if (!list_item)
		return (0);
	((t_pslist *) list_item->content)->pos = (unsigned int) ft_lstsize(*list);
	ft_lstadd_back(&(*list), list_item);
	return (1);
}

int	is_valid_integer(const char *data)
{
	long long int	nb;

	nb = ft_atonb(data);
	return ((nb >= INT_MIN) && (nb <= INT_MAX));
}

void	find_integer(char *arg, int i, int *t, size_t *s, size_t *e, t_list **l)
{
	char	*data;

	if (ft_isdigit(arg[i]) || ((arg[i] == '-') && ft_isdigit(arg[i + 1])))
	{
		if (*t == 0)
		{
			*s = i;
			*t = 1;
		}
		if (*t == 1 && (arg[i + 1] == ' ' || arg[i + 1] == '\0'))
		{
			*e = i;
			data = ft_substr(arg, *s, (*e - *s) + 1);
			if (!is_valid_integer(data) || !can_append_list(data, &(*l)))
				return (*t = -1, free(data), ft_lstclear(&(*l), free));
			free(data);
		}
	}
	else if (arg[i] == ' ')
		*t = 0;
	else
		return (*t = -1, ft_lstclear(&(*l), free));
}

void	*test_argv(int index, t_list *list, char **argv, int *test)
{
	int		j;
	size_t	start;
	size_t	end;

	j = 0;
	start = 0;
	end = 0;
	while (argv[index][j++] != '\0')
	{
		find_integer(argv[index], (j - 1), &test, &start, &end, &list);
		if (*test == -1)
			break;
	}
}

t_list	*extract_integers(int argc, char **argv)
{
	int		i;
	t_list	*list;
	int		test;

	i = 0;
	test = 0;
	list = (t_list *)((void *)0);
	while (++i < argc)
	{
		test_argv(i, list, argv, &test);
		if (test == -1)
			return ((t_list *)((void *)0));
	}
	return (list);
}
