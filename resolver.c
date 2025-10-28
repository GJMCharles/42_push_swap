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

void	command(void (*f)(t_list **, t_list **), t_list **list_a, t_list **list_b)
{
	(*f)(&(*list_a), &(*list_b));
	if (*list_a)
		reset_position(&(*list_a));
	if (*list_b)
		reset_position(&(*list_b));
}

void	resolver(t_list **a, t_list **b)
{
	(void) *b;
	printf("BEFORE: [A]\n");
	ft_lstiter(*a, (void *) print_content);
	printf("\nBEFORE: [B]\n---------\n");
	ft_lstiter(*b, (void *) print_content);
	command(pb, &(*a), &(*b));
	command(pb, &(*a), &(*b));
	command(ss, &(*a), &(*b));
	command(pa, &(*a), &(*b));
	printf("---------\nAFTRER: [A]\n");
	ft_lstiter(*a, (void *) print_content);
	printf("\nAFTER: [B]\n");
	ft_lstiter(*b, (void *) print_content);
}
