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

void	swap_solver(t_list **a, t_list **b)
{
    (void) *b;
    ft_lstiter(*a, (void *)display_item);	
}

int	push_swap(int *tab, unsigned int size)
{
    t_list	*a;
    t_list	*b;

    a = build_list(tab, size);
    if (!a)
        return (0);
    swap_solver(&a, &b);
    ft_lstclear(&a, free);
    return (1);
}
