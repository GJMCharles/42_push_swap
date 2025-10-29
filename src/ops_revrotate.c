/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_revrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:51:01 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:51:04 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_down(t_stack *s)
{
	t_node		*n;

	if (s->size < 2)
		return ;
	n = pop_bottom(s);
	stack_push_top(s, n);
}

void	rra(t_stack *a)
{
	rotate_down(a);
	ft_putendl_fd((char *) __func__, 1);
}

void	rrb(t_stack *b)
{
	rotate_down(b);
	ft_putendl_fd((char *) __func__, 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	ft_putendl_fd((char *) __func__, 1);
}
