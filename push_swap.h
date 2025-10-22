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

typedef struct s_ps_list
{
    int				value;
    unsigned int	pos;
}	t_ps_list;

void	error_found(void);
int		is_number(const char *str);
int		*get_number_tab(int argc, char **argv);
int		is_distinct_tab(int *tab);
void	push_swap(int *tab);

#endif // PUSH_SWAP_H
