/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:18:26 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/19 22:18:26 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    btree_apply_suffix(t_btree * root, void (*apply)(void *))
{
    if (!root)
        return ;
    btree_apply_suffix(root->left, apply);
    btree_apply_suffix(root->right, apply);
    apply(root->item);
}