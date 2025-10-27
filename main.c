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

void	print_content(t_pslist *content)
{
    printf("POS: [%u] VALUE: [%i]\n", content->pos, content->value);
}

int main(int argc, char *argv[])
{
    t_list *a_list;
    t_list *b_list;

    (void) b_list;
    if (argc < 2)
        error_found();
    a_list = extract_integers(argc, argv);
    if (!a_list)
        error_found();
    ft_lstiter(a_list, (void *)print_content);
    ft_lstclear(&a_list, free);
    return (EXIT_SUCCESS);
}
