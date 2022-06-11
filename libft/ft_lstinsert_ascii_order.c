/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_ascii_order.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:43:42 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/19 18:43:42 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// you might need to save next
void    ft_lstinsert_order(t_list **a_list, t_list *insert, int (*cmp)(void *, void*))
{
    t_list * node = *a_list;
    if (node)
    {
        while (node && node->next && (cmp(insert, node) < 0))
            node = node->next;
        if (node->next)
        {

        }
        else
        {
            if (cmp(insert, node) < 0)
                node->next = insert;
        }
    }
    else
        *a_list = insert;
}