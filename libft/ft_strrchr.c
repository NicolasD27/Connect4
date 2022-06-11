/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:55:51 by pcharton          #+#    #+#             */
/*   Updated: 2020/04/29 18:07:30 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		kwak;

	kwak = 0;
	while (*s != 0)
	{
		if (*s == c)
			kwak = 1;
		s++;
	}
	while (*s != c && kwak == 1)
		s--;
	if (*s == c)
		return ((char *)s);
	else
		return (0);
}
