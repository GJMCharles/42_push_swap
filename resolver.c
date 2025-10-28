/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 00:37:02 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 00:37:03 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_content(t_pslist *content)
{
	printf("POS: [%u] VALUE: [%i]\n", content->pos, content->value);
}

void	reset_position(t_list **list)
{
	unsigned int	i;
	t_list			*tmp;

	i = 0;
	if (!(*list))
		return ;
	if (*list)
	{
		i = 0;
		tmp = (*list);
		while (tmp)
		{
			((t_pslist *) tmp->content)->pos = i++;
			tmp = tmp->next;
		}
	}
}

void	command(void (*f)(t_list **, t_list **), t_list **a, t_list **b)
{
	(*f)(&(*a), &(*b));
	if (*a)
		reset_position(&(*a));
	if (*b)
		reset_position(&(*b));
}

t_pslist	*seek_minimum_value(t_list	*list)
{
	int			min;
	t_pslist	*tmp;

	min = INT_MAX;
	while (list)
	{
		if (min > ((t_pslist *) list->content)->value)
		{
			min = ((t_pslist *) list->content)->value;
			tmp = (t_pslist *) list->content;
		}
		list = list->next;
	}
	return (tmp);
}

int	is_sorted_list(t_list *a, t_list *b)
{
	t_list	*tmp;

	if (ft_lstsize(b) || !ft_lstsize(a))
		return (0);
	tmp = a;
	while (tmp)
	{
		if (((t_pslist *)tmp->content)->value > ((t_pslist *)tmp->next->content)->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	resolver(t_list **a, t_list **b)
{
	int			total;
	t_pslist	*item_min;

	while (ft_lstsize(*a))
	{
		total = ft_lstsize(*a);
		item_min = seek_minimum_value(*a);
		if (item_min->pos == 0)
			command(pb, &(*a), &(*b));
		else if ((total / 2) + 1 <= (int)item_min->pos)
			command(rra, &(*a), &(*b));
		else
			command(ra, &(*a), &(*b));
	}
}
