/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:18:32 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/19 22:18:32 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    btree_apply_infix(t_btree * root, void (*apply)(void *))
{
    if (!root)
        return ;
    btree_apply_infix(root->left, apply);
    apply(root->item);
    btree_apply_infix(root->right, apply);
}