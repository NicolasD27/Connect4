/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 09:57:49 by pcharton          #+#    #+#             */
/*   Updated: 2020/05/26 10:29:28 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*get_cleaned;

	node = *lst;
	get_cleaned = node;
	while (node)
	{
		node = node->next;
		del(get_cleaned->content);
		free(get_cleaned);
		get_cleaned = node;
	}
	*lst = NULL;
}
