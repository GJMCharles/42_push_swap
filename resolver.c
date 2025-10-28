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

void	command(void (*f)(t_list **, t_list **), t_list **list_a, t_list **list_b)
{
    (*f)(&(*list_a), &(*list_b));
}

void	resolver(t_list **a, t_list **b)
{
    (void) *b;
    ft_lstiter(*a, (void *) print_content);
    command(ra, &(*a), &(*b));
    ft_lstiter(*a, (void *) print_content);
}
