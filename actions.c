/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 00:50:12 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 00:50:14 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_swap(t_list **list)
{
    (void) *list;
}

void	action_push(t_list **list_src, t_list **list_dest)
{
    (void) *list_src;
    (void) *list_dest;
}

void	action_rotate(t_list **list)
{
    (void) *list;
}

void	action_reverse_rotate(t_list **list)
{
    (void) *list;
}

void	action_mirror(t_list **list_a, t_list **list_b, void (*f)(t_list **))
{
    (*f)(&(*list_a));
    (*f)(&(*list_b));
}