/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:03:59 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/23 01:04:13 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_item(t_pslist *item)
{
	printf("%u ~ %i\n", item->pos, item->value);
}

int	push_swap(int *tab, unsigned int size)
{
	t_list	*a;

	a = build_list(tab, size);
	if (!a)
		return (0);
	ft_lstiter(a, (void *)display_item);
	ft_lstclear(&a, free);
	return (1);
}
