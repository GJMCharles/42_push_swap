/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:51:45 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:51:47 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_pos(t_stack *a)
{
	int			min;
	int			pos;
	int			i;
	t_node		*cur;

	min = INT_MAX;
	pos = 0;
	i = 0;
	cur = a->top;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

static void	sort_three(t_stack *a)
{
	int			x;
	int			y;
	int			z;

	x = a->top->value;
	y = a->top->next->value;
	z = a->bottom->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int			p;

	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return ;
	}
	if (a->size == 3)
		return (sort_three(a));
	while (a->size > 3)
	{
		p = min_pos(a);
		if (p <= a->size / 2)
			while (p-- > 0)
				ra(a);
		else
			while (p++ < a->size)
				rra(a);
		pb(a, b);
	}
	sort_three(a);
	while (b->size)
		pa(a, b);
}
