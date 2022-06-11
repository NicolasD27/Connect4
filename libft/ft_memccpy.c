/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:13:00 by pcharton          #+#    #+#             */
/*   Updated: 2020/05/08 03:29:37 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = dest;
	ptr2 = (unsigned char *)src;
	while (n--)
	{
		if (*ptr2 == (unsigned char)c)
		{
			*ptr1++ = *ptr2;
			return (ptr1);
		}
		*ptr1++ = *ptr2++;
	}
	return (NULL);
}
