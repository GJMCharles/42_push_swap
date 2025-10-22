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

int		is_number(const char *str)
{
    int	i;

    i = 0;
    if ((str[i] == '-') && ft_isdigit(str[i + 1]))
        i += 1;
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i += 1;
    }
    return (1);
}

int		*get_number_tab(int argc, char **argv)
{
    int	*tab;
    int	i;

    tab = (int *) ft_calloc(sizeof(int), argc);
    if (!tab)
        return ((void *)0);
    i = 0;
    while (++i < argc)
    {
        if (!is_number(argv[i]))
        {
            free(tab);
            return ((void *)0);
        }
        tab[i - 1] = ft_atoi(argv[i]);
    }
    return (tab);
}

int		is_distinct_tab(int *tab)
{
    (void) tab;
    return (0);
}