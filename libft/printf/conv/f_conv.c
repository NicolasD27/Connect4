/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 08:44:36 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/23 09:58:40 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "floats.h"
#include "../ft_printf.h"

static void		float_measurements(t_form *infos)
{
	infos->size = infos->len;
	infos->size += sizing_sign(infos->value.dble, infos);
	if (infos->precision == -1)
		infos->precision = 6;
	if (infos->precision > 0 || ft_strchr(infos->flags, '#'))
		infos->size++;
	infos->size += infos->precision;
	if (infos->width > infos->size)
		infos->size = infos->width;
}

void			f_sizing(t_form *infos, va_list args)
{
	infos->value.dble = va_arg(args, double);
	infos->len = order_calculator(infos->value.dble);
	float_measurements(infos);
	infos->format = malloc(sizeof(char) * (1 + infos->size));
	if (!infos->format)
		infos->size = -1;
	else
	{
		infos->format[infos->size] = 0;
		double_extraction(infos, infos->value.dble);
		write(infos->fd, infos->format, infos->size);
		free(infos->format);
	}
}
