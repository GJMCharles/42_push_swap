/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:51:51 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:51:55 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = ((t_node *)(void *)0);
	s->bottom = ((t_node *)(void *)0);
	s->size = 0;
}

void	stack_clear(t_stack *s)
{
	t_node		*tmp;
	t_node		*cur;

	cur = s->top;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	s->top = ((t_node *)(void *)0);
	s->bottom = ((t_node *)(void *)0);
	s->size = 0;
}

t_node	*node_new(int v)
{
	t_node		*n;

	n = (t_node *) malloc(sizeof(t_node));
	if (!n)
		return ((t_node *)(void *)0);
	n->value = v;
	n->index = 0;
	n->prev = ((struct s_node *)(void *)0);
	n->next = ((struct s_node *)(void *)0);
	return (n);
}

int	stack_push_top(t_stack *s, t_node *n)
{
	if (!n)
		return (0);
	n->prev = ((struct s_node *)(void *)0);
	n->next = s->top;
	if (s->top)
		s->top->prev = n;
	s->top = n;
	if (s->size == 0)
		s->bottom = n;
	s->size += 1;
	return (1);
}

int	stack_push_bottom(t_stack *s, t_node *n)
{
	if (!n)
		return (0);
	n->next = ((struct s_node *)(void *)0);
	n->prev = s->bottom;
	if (s->bottom)
		s->bottom->next = n;
	s->bottom = n;
	if (s->size == 0)
		s->top = n;
	s->size += 1;
	return (1);
}
