/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 10:17:50 by pcharton          #+#    #+#             */
/*   Updated: 2021/06/04 16:50:15 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*array;
	unsigned int	i;
	unsigned int	imax;

	i = 0;
	imax = ft_strlen(s);
	array = malloc(sizeof(char) * (imax + 1));
	if (!array)
		return (NULL);
	while (i < imax)
	{
		array[i] = f(i, s[i]);
		i++;
	}
	array[i] = 0;
	return (array);
}
