/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:51:09 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:51:11 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_up(t_stack *s)
{
	t_node	*n;

	if (s->size < 2)
		return ;
	n = pop_top(s);
	stack_push_bottom(s, n);
}

void	ra(t_stack *a)
{
	rotate_up(a);
	ft_putendl_fd((char *) __func__, 1);
}

void	rb(t_stack *b)
{
	rotate_up(b);
	ft_putendl_fd((char *) __func__, 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	ft_putendl_fd((char *) __func__, 1);
}
