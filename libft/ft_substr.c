/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:47:48 by pcharton          #+#    #+#             */
/*   Updated: 2020/05/27 15:44:32 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if ((size_t)ft_strlen(s) < start)
		return (ft_strdup(""));
	else
		ptr = malloc(sizeof(char) * ++len);
	if (ptr == NULL)
		return (ptr);
	else
	{
		i = 0;
		while (s[start] && --len)
			ptr[i++] = s[start++];
		ptr[i] = 0;
		return (ptr);
	}
}
