/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 23:59:40 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/19 23:59:41 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "limits.h"
# include <stdio.h>

typedef struct s_pslist
{
	int				value;
	unsigned int	pos;
}	t_pslist;

void			error_found(void);
t_list			*extract_integers(int argc, char **argv);
long long int	ft_atonb(const char *str);
void			resolver(t_list **list_a, t_list **list_b);

t_list			*create_list_item(int value);

void			pa(t_list **list_a, t_list **list_b);
void			pb(t_list **list_a, t_list **list_b);
void			ra(t_list **list_a, t_list **list_b);
void			rb(t_list **list_a, t_list **list_b);
void			rr(t_list **list_a, t_list **list_b);
void			sa(t_list **list_a, t_list **list_b);
void			sb(t_list **list_a, t_list **list_b);
void			ss(t_list **list_a, t_list **list_b);
void			rra(t_list **list_a, t_list **list_b);
void			rrb(t_list **list_a, t_list **list_b);
void			rrr(t_list **list_a, t_list **list_b);

int				can_append_list(const char *str, t_list **list);
int				is_valid_integer(const char *data);

void			action_swap(t_list **list);
void			action_push(t_list **list_src, t_list **list_dest);
void			action_rotate(t_list **list);
void			action_reverse_rotate(t_list **list);
void			action_mirror(t_list **a, t_list **b, void (*f)(t_list **));

#endif // PUSH_SWAP_H
