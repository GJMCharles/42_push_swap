/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:35:33 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/21 23:59:20 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_found(void)
{
    ft_putendl_fd("Error", STDOUT_FILENO);
    exit(EXIT_FAILURE);
}

int is_number(const char *str)
{
    int	i;

    i = 0;
    if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
        i += 1;
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i += 1;
    }
    return (1);
}
