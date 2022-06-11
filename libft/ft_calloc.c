/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:17:57 by pcharton          #+#    #+#             */
/*   Updated: 2020/05/08 02:17:06 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;

	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (ptr);
	else
	{
		ft_memset(ptr, 0, nmemb * size);
		return (ptr);
	}
}
