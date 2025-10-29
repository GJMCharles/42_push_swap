/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:51:31 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:51:33 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	round_pass(t_stack *a, t_stack *b, int bit)
{
	int			n;
	int			i;
	int			idx;
	t_node		*top;

	n = a->size;
	i = 0;
	while (i < n)
	{
		top = a->top;
		idx = top->index;
		if (((idx >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	while (b->size)
		pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int			bits;
	int			k;

	bits = max_bits_needed(a);
	k = 0;
	while (k < bits)
	{
		round_pass(a, b, k);
		k++;
	}
}
