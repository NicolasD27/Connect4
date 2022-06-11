/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:09:21 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/20 09:25:27 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*q;
	char	*end;

	q = s;
	end = q + n;
	while (q != end)
	{
		*q = (unsigned char)c;
		q++;
	}
	return (q - n);
}
