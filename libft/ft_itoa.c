/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:17:13 by pcharton          #+#    #+#             */
/*   Updated: 2021/06/11 21:27:07 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char	*ft_limit_check(int n)
{
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	else if (n == INT_MAX)
		return (ft_strdup("2147483647"));
	else if (n == 0)
		return (ft_strdup("0"));
	else
		return (0);
}

static int	ft_number_order(int n)
{
	int	count;
	int	value_saver;
	int	start_value;

	count = 1;
	start_value = 1e9;
	while (n / start_value == 0)
		start_value /= 10;
	while (start_value)
	{
		value_saver = start_value * (n / start_value);
		n -= value_saver;
		start_value /= 10;
		count++;
	}
	return (count);
}

void	ft_number_writer(char *str, int n)
{
	int		start_value;
	int		value_saver;
	char	letter;

	start_value = 1e9;
	while (n / start_value == 0)
		start_value /= 10;
	while (start_value)
	{
		letter = '0' + (char)(n / start_value);
		*str = letter;
		value_saver = start_value * (n / start_value);
		n -= value_saver;
		start_value /= 10;
		str++;
	}
	*str = 0;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;

	sign = 0;
	if (n == INT_MIN || n == INT_MAX || n == 0)
		return (ft_limit_check(n));
	else if (n < 0)
		sign++;
	str = malloc(ft_number_order(n) + sign);
	if (str)
	{
		if (sign)
		{
			*str = '-';
			ft_number_writer(str + 1, -n);
		}
		else
			ft_number_writer(str, n);
	}
	return (str);
}
