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

typedef struct s_pslist
{
    int				value;
    unsigned int	pos;
}	t_pslist;

void	error_found(void);
int		is_number(const char *str);
int		*get_number_tab(int argc, char **argv, unsigned int *len);
int		is_distinct_tab(int *tab, unsigned int len);
int		push_swap(int *tab, unsigned int size);
void	delete_item(t_pslist *list);

#endif // PUSH_SWAP_H
