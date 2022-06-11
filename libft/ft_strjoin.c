/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:00:23 by pcharton          #+#    #+#             */
/*   Updated: 2021/06/11 21:30:49 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenstr(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = malloc(sizeof(char *) * (ft_lenstr(s1) + ft_lenstr(s2)));
	if (ptr == NULL)
		return (NULL);
	else
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			ptr[i + j] = s2[j];
			j++;
		}
		ptr[i + j] = 0;
		return (ptr);
	}
}
