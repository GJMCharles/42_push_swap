/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:04:15 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 08:04:17 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **list_a, t_list **list_b)
{
    action_push(&(*list_b), &(*list_a));
    ft_putendl_fd((char *) __func__, STDOUT_FILENO);
}

void	pb(t_list **list_a, t_list **list_b)
{
    action_push(&(*list_a), &(*list_b));
    ft_putendl_fd((char *) __func__, STDOUT_FILENO);
}
