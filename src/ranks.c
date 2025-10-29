/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:51:38 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/28 22:51:40 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_array(t_stack *a, int *arr)
{
	int		i;
	t_node	*cur;

	cur = a->top;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
}

static void	quick_sort(int *arr, int left, int right)
{
	int		i;
	int		j;
	int		pivot;

	if (left >= right)
		return ;
	i = left;
	j = right;
	pivot = arr[(left + right) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
			swap(&arr[i++], &arr[j--]);
	}
	if (left < j)
		quick_sort(arr, left, j);
	if (i < right)
		quick_sort(arr, i, right);
}

void	assign_indices(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*cur;

	arr = (int *) malloc(sizeof(int) * a->size);
	if (!arr)
		error_exit();
	fill_array(a, arr);
	quick_sort(arr, 0, a->size - 1);
	cur = a->top;
	while (cur)
	{
		i = 0;
		while (arr[i] != cur->value)
			i++;
		cur->index = i;
		cur = cur->next;
	}
	free(arr);
}

int	max_bits_needed(t_stack *a)
{
	int			max;
	int			bits;
	t_node		*cur;

	max = 0;
	cur = a->top;
	while (cur)
	{
		if (cur->index > max)
			max = cur->index;
		cur = cur->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
