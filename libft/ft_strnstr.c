/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 13:27:20 by pcharton          #+#    #+#             */
/*   Updated: 2020/05/23 19:07:52 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strncmp(small, "", 1) == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (small[j] == big[i + j] && small[j] && big[i + j] && i + j < len)
			j++;
		if (small[j] == 0)
			return ((char *)&big[i]);
		else
		{
			i++;
			j = 0;
		}
	}
	return (NULL);
}
