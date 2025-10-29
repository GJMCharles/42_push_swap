/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:51:23 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:51:25 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

static int	is_numstr(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	if (is_sign(s[0]) && s[1] != '\0')
		i++;
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	safe_atoi(const char *s, int *out)
{
	long	val;
	int		sign;
	int		i;

	val = 0;
	sign = 1;
	i = 0;
	if (is_sign(s[i]))
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		val = val * 10 + (s[i] - '0');
		if (sign == 1 && val > INT_MAX)
			return (0);
		if (sign == -1 && - val < INT_MIN)
			return (0);
		i++;
	}
	*out = (int)(val * sign);
	return (1);
}

static int	push_tokens(char **tokens, t_stack *a)
{
	int		v;
	int		k;
	t_node	*n;

	k = 0;
	while (tokens[k])
	{
		if (!is_numstr(tokens[k]) || !safe_atoi(tokens[k], &v))
			return (0);
		if (contains_value(a, v))
			return (0);
		n = node_new(v);
		if (!n)
			return (0);
		if (!stack_push_bottom(a, n))
			return (0);
		k++;
	}
	return (1);
}

int	parse_args(int ac, char **av, t_stack *a)
{
	int		i;
	char	**sp;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (0);
		sp = ft_split(av[i], ' ');
		if (!sp)
			return (0);
		if (!push_tokens(sp, a))
		{
			ft_free_split(sp);
			return (0);
		}
		ft_free_split(sp);
		i++;
	}
	return (1);
}
