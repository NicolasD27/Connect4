/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 13:48:28 by pcharton          #+#    #+#             */
/*   Updated: 2021/06/11 21:31:07 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	sum;

	i = ft_strlen(dst);
	j = ft_strlen((char *)src);
	sum = i + j;
	if (size <= i)
		return (size + j);
	j = 0;
	while (src[j] && (j + i < size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (sum);
}
