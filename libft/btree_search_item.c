/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:34:29 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/19 22:34:29 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	*btree_search_item(t_btree *root,
			void *data_ref,
			int (*cmpf)(void *, void *))
{
    if (!root)
        return (NULL);
    int res = cmpf(data_ref, root->item);
    if (!res)
        return (root);
    else if (res < 0)
        return (btree_search_item(root->left, data_ref, cmpf)); 
    else 
        return (btree_search_item(root->right, data_ref, cmpf)); 
}