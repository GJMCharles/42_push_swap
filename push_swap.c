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
#include <stdio.h>

t_pslist	*create_item(unsigned int pos, int value)
{
    t_pslist *item;

    item = (t_pslist *) malloc(sizeof(t_pslist));
    if (!item)
        return ((void *)0);
    item->value = value;
    item->pos = pos;
    return (item);
}

void	delete_item(t_pslist *item)
{
    free(item);
}

void	print_info(t_pslist *item)
{
    printf("pos: %u ~ value: %i\n", item->pos, item->value);
}

t_list		*build_list(int *tab, unsigned int size)
{
    t_list			*list;
    unsigned int	i;

    i = 0;
    while (i < size)
    {
        if (i == 0)
            list = ft_lstnew(create_item(i, tab[i]));
        else
            ft_lstadd_back(&list, ft_lstnew(create_item(i, tab[i])));
        i += 1;
    }
    ft_lstiter(list, (void *)print_info);
    ft_lstclear(&list, (void *)delete_item);
    return ((void *)0);
}

// void	delete_item(t_pslist *item)
// {
// 	free(item);
// 	item = ((void *)0);
// }

int		push_swap(int *tab, unsigned int size)
{
    t_list *a;
    // t_pslist *b;

    a = build_list(tab, size);
    if (!a)
        return (0);
    // solver(a);
    return (1);
}
