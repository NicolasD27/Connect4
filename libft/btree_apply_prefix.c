/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:18:16 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/19 22:18:16 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    btree_apply_prefix(t_btree * root, void (*apply)(void *))
{
    if (!root)
        return ;
    apply(root->item);
    btree_apply_prefix(root->left, apply);
    btree_apply_prefix(root->right, apply);
}