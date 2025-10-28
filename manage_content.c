/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:26:44 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 11:26:54 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*create_content(int value)
{
	t_pslist	*content;

	content = (t_pslist *) ft_calloc(1, sizeof(t_pslist));
	if (!content)
		return ((t_pslist *)(void *)0);
	content->value = value;
	content->pos = 0;
	return (content);
}
