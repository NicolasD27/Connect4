/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:01:58 by pcharton          #+#    #+#             */
/*   Updated: 2020/04/28 17:03:44 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (&((char *)s)[i]);
		}
		else
			i++;
	}
	if (c == 0)
		return (&((char *)s)[i]);
	else
		return (0);
}
