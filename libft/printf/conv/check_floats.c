/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 15:31:19 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/23 14:22:35 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "floats.h"
#include "../ft_printf.h"

int			infinity_and_number_check(double value)
{
	unsigned long long	exponent;
	t_bool				sign;

	ft_memcpy(&exponent, &value, 8);
	sign = exponent >> 63;
	if ((exponent & 0x7FF0000000000000) == 0x7FF0000000000000
		&& (exponent & 0xFFFFFFFFFFFFF) == 0)
	{
		if (sign == 1)
			return (-1);
		else
			return (1);
	}
	else if ((exponent & 0x7FF0000000000000) == 0x7FF0000000000000
		&& (exponent & 0xFFFFFFFFFFFFF) != 0)
		return (2);
	else
		return (0);
}

int			check_floats(t_form *infos, t_float *extract)
{
	double	value;
	int		output;

	value = infos->value.dble;
	output = infinity_and_number_check(value);
	if (output)
	{
		if (output == 1 || output == -1)
		{
			infos->len = 3;
			extract->limits = "inf";
		}
		else if (output == 2)
		{
			extract->sign = 0;
			infos->len = 3;
			extract->limits = "nan";
		}
		resize_buffer(infos);
		ft_strcpy(&infos->format[extract->sign], &extract->limits[0], 3);
		infos->len += extract->sign;
	}
	return (output);
}

void		resize_buffer(t_form *infos)
{
	char	*ptr;

	ptr = ft_strchr(infos->flags, '0');
	if (ptr)
		*(ptr - 1) = ',';
	if (infos->width > infos->len)
		infos->size = infos->width;
	else
		infos->size = infos->len;
	infos->format = malloc(sizeof(char) * (1 + infos->size));
	if (!infos->format)
		infos->size = -1;
	else
	{
		infos->format[infos->size] = 0;
		f_adding_sign(infos);
	}
}
