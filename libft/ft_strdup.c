/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:52:26 by pcharton          #+#    #+#             */
/*   Updated: 2020/05/08 03:48:07 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s[i])
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (ptr);
	else
	{
		while (*s)
			*ptr++ = *s++;
		*ptr = 0;
		return (ptr - i);
	}
}

char	*ft_strndup(const char * s, size_t n)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * (n + 1));
	if (ptr)
		ft_strlcpy(ptr, s, n + 1);
	return (ptr);
}