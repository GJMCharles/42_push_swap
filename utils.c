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

void		error_found(void)
{
    char	message[6];

    message[0] = 'E';
    message[1] = 'r';
    message[2] = 'r';
    message[3] = 'o';
    message[4] = 'r';
    message[5] = '\0';
    ft_putendl_fd(message, STDOUT_FILENO);
    exit(EXIT_FAILURE);
}

long long int	ft_atonb(const char *str)
{
    int				i;
    int				neg;
    long long int	nb;

    i = 0;
    nb = 0;
    neg = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i += 1;
    if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
    {
        if (str[i] == '-')
            neg = -1;
        i += 1;
    }
    while (ft_isdigit(str[i]))
    {
        nb = (nb * 10) + (str[i] - 48);
        i += 1;
    }
    return (nb * neg);
}

// int	is_distinct_tab(int *tab, unsigned int len)
// {
// 	int				*test_tab;
// 	unsigned int	i;
// 	unsigned int	j;
// 	test_tab = (int *)ft_calloc(sizeof(int), len + 1);
// 	if (!test_tab)
// 		return (0);
// 	i = 0;
// 	while (i++ < (len - 1))
// 	{
// 		j = 0;
// 		while (j++ < (i - 1))
// 		{
// 			if (test_tab[j - 1] == tab[i - 1])
// 			{
// 				free(test_tab);
// 				return (0);
// 			}
// 		}
// 		test_tab[j - 1] = tab[i - 1];
// 	}
// 	free(test_tab);
// 	return (1);
// }
