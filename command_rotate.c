/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:04:27 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 08:04:28 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **list_a, t_list **list_b)
{
    (void) *list_b;
    action_rotate(&(*list_a));
    ft_putendl_fd((char *) __func__, STDOUT_FILENO);
}

void	rb(t_list **list_a, t_list **list_b)
{
    (void) *list_a;
    action_rotate(&(*list_b));
    ft_putendl_fd((char *) __func__, STDOUT_FILENO);
}

void	rr(t_list **list_a, t_list **list_b)
{
    action_mirror(&(*list_a), &(*list_b), action_rotate);
    ft_putendl_fd((char *) __func__, STDOUT_FILENO);
}
