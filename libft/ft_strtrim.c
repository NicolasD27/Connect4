/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:55:33 by pcharton          #+#    #+#             */
/*   Updated: 2020/05/20 17:45:22 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (i < k && s1[k] && ft_strchr(set, s1[k]))
		k--;
	if (i >= k)
		return (ft_strdup(""));
	else
		return (ft_substr(&s1[i], 0, k + 1 - i));
}
