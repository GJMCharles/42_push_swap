/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_integers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 04:25:44 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/27 04:25:56 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		is_unique_value(void *item, char *value)
// {
// 	if (!item)
// 		return (0);
// 	return (((t_pslist *)item)->value != ft_atoi(value));
// }
int can_append_list(const char *str, t_list **list)
{
    t_pslist	*content;
    t_list		*tmp_list;

    content = (t_pslist *) ft_calloc(1, sizeof(t_pslist));
    if (!content)
        return (0);
    content->value = ft_atonb(str);
    content->pos = (unsigned int) ft_lstsize(*list);
    tmp_list = ft_lstnew(content);
    if (!tmp_list)
        return (free(content), 0);
    ft_lstadd_back(&(*list), tmp_list);
    return (1);
}

int is_valid_integer(const char *data)
{
    long long int	nb;

    nb = ft_atonb(data);
    return ((nb >= -2147483648) && (nb <= 2147483647));
}

void find_integer(char *arg, int i, int *em, size_t *s, size_t *e, t_list **l)
{
    char	*data;

    if (ft_isdigit(arg[i]) || ((arg[i] == '-') && ft_isdigit(arg[i + 1])))
    {
        if (*em == 0)
        {
            *s = i;
            *em = 1;
        }
        if (*em == 1 && (arg[i + 1] == ' ' || arg[i + 1] == '\0'))
        {
            *e = i;
            data = ft_substr(arg, *s, (*e - *s) + 1);
            if (!is_valid_integer(data) || !can_append_list(data, &(*l)))
                return (free(data), ft_lstclear(&(*l), free));
            free(data);
        }
    }
    else if (arg[i] == ' ')
        *em = 0;
    else
        ft_lstclear(&(*l), free);
    // char *value;
    // (void)*l;
    // printf("[%s]\n", arg);
    // if (ft_isdigit(arg[i]) || ((arg[i] == '-') && ft_isdigit(arg[i + 1])))
    // {
    // 	if (*em == 0)
    // 	{
    // 		*s = i;
    // 		*em = 1;
    // 	}
    // 	if (*em == 1 && (arg[i + 1] == ' ' || arg[i + 1] == '\0'))
    // 	{
    // 		*e = i;
    // 		value = ft_substr(arg, *s, (*e - *s) + 1);
    // 		printf("[_%s_]\n", value);
    // 		printf("Start: [%i] - End:[%i]\n", (int) *s, (int) *e);
    // 		// if (!is_valid_integer(value) || !can_append_list(value, &(*l)))
    // 			// ft_lstclear(&(*l), free);
    // 		free(value);
    // 	}
    // }
    // else if (arg[i] == ' ')
    // 	*em = 0;
    // // else
    // // 	ft_lstclear(&(*l), free);
}

t_list *extract_integers(int argc, char **argv)
{
    int		i;
    t_list	*list;
    int		j;
    int		empty;
    size_t	start;
    size_t	end;

    i = 0;
    list = (t_list *)((void *)0);
    while (++i < argc)
    {
        j = 0;
        empty = 0;
        start = 0;
        end = 0;
        while (argv[i][j++] != '\0')
        {
            find_integer(argv[i], (j - 1), &empty, &start, &end, &list);
        }
        printf("{%s}\n", (char *)list);
    }
    return (list);
}
