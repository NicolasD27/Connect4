/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:23:24 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/20 09:17:51 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			order_calculator(long long nb)
{
	int	order;

	order = 0;
	if (nb == LONG_MIN)
		return (19);
	if (nb < 0)
		nb = -nb;
	else if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		order++;
	}
	return (order);
}

int			unsigned_order(unsigned long long nb, int base)
{
	int		order;

	order = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		order++;
	}
	return (order);
}

void		ft_lltoa(long long nb, char *ptr)
{
	int		order;

	if (nb == LLONG_MIN)
	{
		ft_strlcpy(ptr, "9223372036854775808", 19);
		return ;
	}
	order = order_calculator(nb) - 1;
	if (nb == 0)
		ptr[0] = '0';
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		ptr[order] = '0' + (nb % 10);
		nb /= 10;
		order--;
	}
}

void		ft_ulltoa(unsigned long long nb, char *ptr)
{
	int		order;

	order = unsigned_order(nb, 10) - 1;
	if (nb == 0)
		ptr[0] = '0';
	while (nb != 0)
	{
		ptr[order] = '0' + (nb % 10);
		nb /= 10;
		order--;
	}
}

void		ft_ulltoa_base_16(unsigned long long nb, char *ptr)
{
	int		order;

	order = unsigned_order(nb, 16);
	if (nb == 0)
		ptr[0] = '0';
	while (nb != 0)
	{
		if ((nb % 16) > 9)
			ptr[order - 1] = 'a' + (nb % 16) - 10;
		else
			ptr[order - 1] = '0' + (nb % 16);
		nb /= 16;
		order--;
	}
}
