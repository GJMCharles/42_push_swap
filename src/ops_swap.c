/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:51:16 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:51:18 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top_two(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = ((struct s_node *)(void *)0);
	second->next = first;
	first->prev = second;
	s->top = second;
	if (s->size == 2)
		s->bottom = first;
}

void	sa(t_stack *a)
{
	swap_top_two(a);
	ft_putendl_fd((char *) __func__, 1);
}

void	sb(t_stack *b)
{
	swap_top_two(b);
	ft_putendl_fd((char *) __func__, 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
	ft_putendl_fd((char *) __func__, 1);
}
