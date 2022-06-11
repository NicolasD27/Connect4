/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:30:10 by pcharton          #+#    #+#             */
/*   Updated: 2021/06/11 21:28:34 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_lst;
	t_list	*new_lst_return;

	node = lst;
	new_lst = ft_lstnew(f(node->content));
	if (!new_lst)
		return (NULL);
	new_lst_return = new_lst;
	while (node)
	{
		node = node->next;
		new_lst = new_lst->next;
		new_lst = ft_lstnew(f(node->content));
		if (!new_lst)
		{
			ft_lstclear(&new_lst_return, del);
			return (NULL);
		}
	}
	return (new_lst_return);
}
