/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:04:21 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 08:04:22 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **list_a, t_list **list_b)
{
	(void) *list_b;
	action_swap(&(*list_a));
	ft_putendl_fd((char *) __func__, STDOUT_FILENO);
}

void	sb(t_list **list_a, t_list **list_b)
{
	(void) *list_a;
	action_swap(&(*list_b));
	ft_putendl_fd((char *) __func__, STDOUT_FILENO);
}

void	ss(t_list **list_a, t_list **list_b)
{
	action_mirror(&(*list_a), &(*list_b), action_swap);
	ft_putendl_fd((char *) __func__, STDOUT_FILENO);
}
