/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:59:02 by pcharton          #+#    #+#             */
/*   Updated: 2021/06/11 21:31:19 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] < s2[i] || s1[i] > s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		else if (i == n - 1 && s1[i] == s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		else
			i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
