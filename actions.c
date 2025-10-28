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
	(void) *list;
}

void	action_push(t_list **list_src, t_list **list_dest)
{
	(void) *list_src;
	(void) *list_dest;
}

void	action_rotate(t_list **list)
{
	t_pslist	*first;
	t_pslist	*last;
	t_pslist	**tmp;

	first = (t_pslist *) (*list)->content;
	last = (t_pslist *) ft_lstlast(*list)->content;

	tmp = &first;
	// first = &last;
	// last = tmp;
}

void	action_reverse_rotate(t_list **list)
{
	t_list		*tmp_list;
	t_list		*saved_list_item;
	t_pslist	*duplicate_content;

	if (!(*list) || !(*list)->next)
		return ;
	tmp_list = ft_lstlast(*list);
	duplicate_content = create_content(((t_pslist *)(tmp_list)->content)->value);
	if (!duplicate_content)
		return ;
	saved_list_item = ft_lstnew(duplicate_content);
	if (!saved_list_item)
	{
		free(duplicate_content);
		return ;
	}
	ft_lstdelone(*list, free);
	*list = tmp_list;
	ft_lstadd_back(&(*list), saved_list_item);
}

void	action_mirror(t_list **list_a, t_list **list_b, void (*f)(t_list **))
{
	(*f)(&(*list_a));
	(*f)(&(*list_b));
}
