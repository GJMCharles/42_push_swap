/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:46:38 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/26 19:48:48 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atonb(const char *nptr)
{
	int				i;
	int				neg;
	long long int	nb;

	i = 0;
	nb = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i += 1;
	if ((nptr[i] == '+' || nptr[i] == '-') && ft_isdigit(nptr[i + 1]))
	{
		if (nptr[i] == '-')
			neg = -1;
		i += 1;
	}
	while (ft_isdigit(nptr[i]))
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i += 1;
	}
	return (nb * neg);
}
