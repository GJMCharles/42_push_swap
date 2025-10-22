/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 23:59:33 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/21 23:58:08 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
    int i;

    if (argc < 2)
        error_found();
    i = 1;
    while (i++ < argc)
    {
        printf("%d\n", ft_atoi(argv[i - 1]));
    }
    return (EXIT_SUCCESS);
}
