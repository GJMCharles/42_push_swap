/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 02:01:38 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/26 02:01:40 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*create_item(unsigned int pos, int value)
{
	t_pslist	*item;

	item = (t_pslist *) malloc(sizeof(t_pslist));
	if (!item)
		return ((t_pslist *)(void *)0);
	item->value = value;
	item->pos = pos;
	return (item);
}

t_list	*delete_list(t_list *list)
{
	if (ft_lstsize(list))
		ft_lstclear(&list, free);
	return ((t_list *)(void *)0);
}

t_list	*build_list(int *tab, unsigned int size)
{
	unsigned int	i;
	t_list			*list;
	t_list			*tmp_list;
	t_pslist		*tmp_content;

	i = 0;
	while (i < (size - 1))
	{
		tmp_content = create_item(i, tab[i]);
		if (!tmp_content)
			return (delete_list(list));
		tmp_list = ft_lstnew(tmp_content);
		if (!tmp_list)
		{
			free(tmp_content);
			return (delete_list(list));
		}
		if (i == 0)
			list = tmp_list;
		else
			ft_lstadd_back(&list, tmp_list);
		i += 1;
	}
	return (list);
}
