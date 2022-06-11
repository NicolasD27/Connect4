/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_extraction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:04:11 by pcharton          #+#    #+#             */
/*   Updated: 2020/09/06 14:18:31 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "floats.h"
#include "../ft_printf.h"

int				f_adding_sign(t_form *infos)
{
	unsigned long long	sign;

	ft_memcpy(&sign, &infos->value.dble, 8);
	sign >>= 63;
	if (sign || (ft_strchr(infos->flags, '+'))
		|| (ft_strchr(infos->flags, ' ')))
	{
		if (sign)
			infos->format[0] = '-';
		else if ((ft_strchr(infos->flags, '+')) && sign == 0)
			infos->format[0] = '+';
		else if ((ft_strchr(infos->flags, ' ')) && sign == 0)
			infos->format[0] = ' ';
		return (TRUE);
	}
	else
		return (FALSE);
}

int				put_decimal_in_str(t_form *infos, t_float extract)
{
	int		i;
	int		stock;

	i = 0;
	stock = infos->len;
	while (i < infos->precision)
	{
		extract.decimal *= 10;
		extract.tmp = extract.decimal;
		infos->format[stock + i] = '0' + extract.tmp;
		extract.decimal -= extract.tmp;
		i++;
	}
	if (extract.decimal >= 0.50)
	{
		if (infos->format[stock + --i] == '9')
			start_rounding(&infos->format[stock + i], infos);
		else
		{
			if ((extract.integer & 1) == 1)
				infos->format[stock + i] += 1;
		}
	}
	return (infos->precision);
}

void			float_width_formatting(t_form *infos, t_float *extract)
{
	int		len;

	len = infos->width - infos->len;
	if ((ft_strchr(infos->flags, '-')) != NULL)
		ft_memset(&infos->format[infos->len], ' ', len);
	else if (ft_strchr(infos->flags, '0') != NULL)
	{
		ft_memmove(&infos->format[len + extract->sign],
				&infos->format[extract->sign], infos->len);
		ft_memset(&infos->format[extract->sign], '0', len);
	}
	else if ((ft_strchr(infos->flags, '-')) == NULL
			&& infos->width > infos->len)
	{
		ft_memmove(&infos->format[len], &infos->format[0], infos->len);
		ft_memset(&infos->format[0], ' ', len);
	}
}

static t_float	float_preparation(t_form *infos, double val, t_float *extract)
{
	if (val < 0)
		extract->integer = -val;
	else
		extract->integer = val;
	extract->sign = f_adding_sign(infos);
	extract->integer_len = extract->sign + infos->len;
	ft_memcpy(&extract->bin_rpz, &val, 8);
	if (extract->bin_rpz >> 63)
		extract->decimal = -1.0 * (val + extract->integer);
	else
		extract->decimal = (val - extract->integer);
	return (*extract);
}

void			double_extraction(t_form *infos, double value)
{
	t_float	extract;
	t_bool	float_point;

	float_point = 0;
	extract = float_preparation(infos, value, &extract);
	ft_ulltoa(extract.integer, &infos->format[extract.sign]);
	if (check_floats(infos, &extract) != 0)
		float_width_formatting(infos, &extract);
	else
	{
		if (infos->precision > 0 || ft_strchr(infos->flags, '#'))
		{
			infos->format[infos->len + extract.sign] = '.';
			float_point = 1;
		}
		infos->len += extract.sign;
		infos->len += float_point;
		if (infos->precision >= 0)
			infos->len += put_decimal_in_str(infos, extract);
		if (infos->len < infos->width)
			float_width_formatting(infos, &extract);
	}
}
