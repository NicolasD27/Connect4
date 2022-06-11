/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 01:24:39 by pcharton          #+#    #+#             */
/*   Updated: 2020/05/20 17:51:39 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	size_t	number;
	char	letter;
	int		divisor;

	number = n;
	letter = '-';
	divisor = 1000000000;
	if (n < 0)
	{
		write(1, &letter, 1);
		number = -n;
	}
	while (number % divisor != 0)
	{
		letter = '0' + (number / divisor);
		if (number / divisor != 0)
			write(1, &letter, 1);
		number /= 10;
		divisor /= 10;
	}
}
