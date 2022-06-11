/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 13:15:09 by pcharton          #+#    #+#             */
/*   Updated: 2020/05/07 22:17:48 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j])
		j++;
	i = 0;
	while (src[i] && (i + 1 < size))
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = 0;
	return (j);
}
