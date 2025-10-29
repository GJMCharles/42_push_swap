/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:50:52 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:50:55 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node		*n;

	n = pop_top(b);
	if (!n)
		return ;
	stack_push_top(a, n);
	ft_putendl_fd((char *) __func__, 1);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node		*n;

	n = pop_top(a);
	if (!n)
		return ;
	stack_push_top(b, n);
	ft_putendl_fd((char *) __func__, 1);
}
