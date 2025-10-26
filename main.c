/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 23:59:33 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/23 01:04:35 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	unsigned int	len;
	int				*tab;

	if (argc < 2)
		error_found();
	tab = get_integer_tab(argc, argv, &len);
	if (!tab)
		error_found();
	if (!is_distinct_tab(tab, len) || !push_swap(tab, len - 1))
	{
		free(tab);
		error_found();
	}
	free(tab);
	return (EXIT_SUCCESS);
}
