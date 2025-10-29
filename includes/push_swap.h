/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:50:14 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:50:17 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}	t_stack;

/*Parsing*/
int					parse_args(int ac, char **av, t_stack *a);
int					is_sorted(t_stack *a);

/*Errors*/
void				error_exit(void);

/*utils*/
void				stack_init(t_stack *s);
void				stack_clear(t_stack *s);
int					stack_push_top(t_stack *s, t_node *n);
int					stack_push_bottom(t_stack *s, t_node *n);
t_node				*node_new(int v);
t_node				*pop_top(t_stack *s);
t_node				*pop_bottom(t_stack *s);
int					contains_value(t_stack *s, int v);

/*operations*/
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/*Sorting*/
void				sort_small(t_stack *a, t_stack *b);
void				radix_sort(t_stack *a, t_stack *b);

/*Rank indices*/
void				assign_indices(t_stack *a);
int					max_bits_needed(t_stack *a);
void				ft_free_split(char **arr);
void				assign_indices(t_stack *a);
void				swap(int *a, int *b);

#endif
