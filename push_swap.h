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

# include "libft.h"
/*
Do Not Forget to DELETE <stdio.h> before FINAL PUSH
*/
# include <stdio.h>

typedef struct s_pslist
{
    int				value;
    unsigned int	pos;
}	t_pslist;

void			error_found(void);
t_list			*extract_integers(int argc, char **argv);
long long int	ft_atonb(const char *str);
void			push_swap(t_list **a, t_list **b);
void			action_swap(t_list **list);
void			action_push(t_list **list_src, t_list **list_dest);
void			action_rotate(t_list **list);
void			action_reverse_rotate(t_list **list);
void			action_mirror(t_list **list_a, t_list **list_b, void (*f)(t_list **));

#endif // PUSH_SWAP_H
