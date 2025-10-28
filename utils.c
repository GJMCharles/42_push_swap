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

int	can_append_list(const char *str, t_list **list)
{
	int			value;
	t_list		*tmp;
	t_list		*list_item;

	value = ft_atonb(str);
	tmp = *list;
	while (tmp)
	{
		if (((t_pslist *)tmp->content)->value == value)
			return (0);
		tmp = tmp->next;
	}
	list_item = create_list_item(value);
	if (!list_item)
		return (0);
	((t_pslist *) list_item->content)->pos = (unsigned int) ft_lstsize(*list);
	ft_lstadd_back(&(*list), list_item);
	return (1);
}

int	is_valid_integer(const char *data)
{
	long long int	nb;

	nb = ft_atonb(data);
	return ((nb >= INT_MIN) && (nb <= INT_MAX));
}
