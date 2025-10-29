/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:50:44 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:50:46 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_dispatch(t_stack *a, t_stack *b)
{
	if (a->size <= 1)
		return ;
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
		sort_small(a, b);
	else
	{
		assign_indices(a);
		radix_sort(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	stack_init(&a);
	stack_init(&b);
	if (ac == 1)
		error_exit();
	if (!parse_args(ac, av, &a))
	{
		stack_clear(&a);
		error_exit();
	}
	sort_dispatch(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (EXIT_SUCCESS);
}
