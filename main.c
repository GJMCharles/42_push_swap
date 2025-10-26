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
	printf("1\n");
	if (!tab)
		error_found();
	printf("2\n");
	if (!is_distinct_tab(tab, len))
	{
		free(tab);
		error_found();
	}
	printf("3\n");
	if (!push_swap(tab, len))
	{
		free(tab);
		error_found();
	}
	printf("4\n");
	free(tab);
	return (EXIT_SUCCESS);
}
