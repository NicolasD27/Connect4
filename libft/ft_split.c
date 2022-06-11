/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:06:34 by pcharton          #+#    #+#             */
/*   Updated: 2021/06/03 19:36:38 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	occurence_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
		}
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static size_t	my_specialstrlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_my_tab(char **tab, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	tab = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	imax;

	imax = occurence_count(s, c);
	tab = malloc(sizeof(char *) * (imax + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < imax)
	{
		while (*s && *s == c)
			s++;
		tab[i] = ft_substr(s, 0, my_specialstrlen(s, c));
		if (!tab[i])
		{
			free_my_tab(tab, i);
			return (tab);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
