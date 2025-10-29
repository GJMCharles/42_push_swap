/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:50:36 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:50:39 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	char	message[6];

	message[0] = 'E';
	message[1] = 'r';
	message[2] = 'r';
	message[3] = 'o';
	message[4] = 'r';
	message[5] = '\0';
	ft_putendl_fd(message, 1);
	exit(EXIT_FAILURE);
}

t_node	*pop_top(t_stack *s)
{
	t_node		*n;

	if (s->size == 0)
		return ((t_node *)(void *)0);
	n = s->top;
	s->top = n->next;
	if (s->top)
		s->top->prev = ((struct s_node *)(void *)0);
	else
		s->bottom = ((t_node *)(void *)0);
	n->next = ((struct s_node *)(void *)0);
	n->prev = ((struct s_node *)(void *)0);
	s->size -= 1;
	return (n);
}

t_node	*pop_bottom(t_stack *s)
{
	t_node		*n;

	if (s->size == 0)
		return ((t_node *)(void *)0);
	n = s->bottom;
	s->bottom = n->prev;
	if (s->bottom)
		s->bottom->next = ((struct s_node *)(void *)0);
	else
		s->top = ((t_node *)(void *)0);
	n->next = ((struct s_node *)(void *)0);
	n->prev = ((struct s_node *)(void *)0);
	s->size -= 1;
	return (n);
}

int	contains_value(t_stack *s, int v)
{
	t_node		*cur;

	cur = s->top;
	while (cur)
	{
		if (cur->value == v)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_node		*cur;

	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
