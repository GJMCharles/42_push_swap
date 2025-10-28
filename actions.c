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

#include "libft/libft.h"
#include "push_swap.h"

void	action_swap(t_list **list)
{
	t_list	*old_item;
	t_list	*new_item;

	if (!(*list) || !(*list)->next)
		return ;
	old_item = (*list)->next;
	new_item = create_list_item(((t_pslist *)old_item->content)->value);
	(*list)->next = old_item->next;
	ft_lstdelone(old_item, free);
	ft_lstadd_front(&(*list), new_item);
}

void	action_push(t_list **list_src, t_list **list_dest)
{
	(void) *list_src;
	(void) *list_dest;
}

void	action_rotate(t_list **list)
{
	t_list	*list_item;
	t_list	*new_item;

	if (!(*list) || !(*list)->next)
		return ;
	new_item = create_list_item(((t_pslist *)(*list)->content)->value);
	if (!new_item)
		return ;
	list_item = (*list)->next;
	ft_lstdelone(*list, free);
	*list = list_item;
	ft_lstadd_back(&(*list), new_item);
}

void	action_reverse_rotate(t_list **list)
{
	t_list	*last_item;
	t_list	*list_item;
	t_list	*new_item;

	if (!(*list) || !(*list)->next)
		return ;
	last_item = ft_lstlast(*list);
	new_item = create_list_item(((t_pslist *)(last_item)->content)->value);
	if (!new_item)
		return ;
	list_item = *list;
	while (list_item->next != last_item)
		list_item = list_item->next;
	list_item->next = (t_list *)((void *)0);
	ft_lstdelone(last_item, free);
	ft_lstadd_front(&(*list), new_item);
}

void	action_mirror(t_list **list_a, t_list **list_b, void (*f)(t_list **))
{
	(*f)(&(*list_a));
	(*f)(&(*list_b));
}
