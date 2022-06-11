/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:11:13 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/19 22:11:13 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree * btree_create_node(void * item)
{
    t_btree * new = ft_calloc(1, sizeof(t_btree));
    if (new)
        new->item = item;
    return (new);
}