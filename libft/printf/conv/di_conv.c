/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:21:21 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/23 09:58:34 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long long	signed_length_modif(int lm, va_list args)
{
	long long	nb;

	if (lm == -2)
		nb = (signed char)va_arg(args, int);
	else if (lm == -1)
		nb = (signed short)va_arg(args, int);
	else if (lm == 1)
		nb = (long)va_arg(args, long);
	else if (lm == 2)
		nb = va_arg(args, long long);
	else
		nb = (int)va_arg(args, int);
	return (nb);
}

void				di_sizing(t_form *infos, va_list args)
{
	infos->value.ll = signed_length_modif(infos->length_modif, args);
	infos->len = order_calculator(infos->value.ll);
	infos->size = infos->len;
	if (infos->precision > infos->len)
		infos->size = infos->precision;
	if (infos->value.ll < 0 || (infos->value.ll > 0
								&& ((ft_strchr(infos->flags, '+'))
									|| (ft_strchr(infos->flags, ' ')))))
		infos->size++;
	if (infos->width > infos->size)
		infos->size = infos->width;
	infos->format = malloc(sizeof(char) * (1 + infos->size));
	if (!infos->format)
		infos->written = -1;
	else
	{
		infos->format[infos->size] = 0;
		ft_lltoa(infos->value.ll, infos->format);
		int_precision_formatting(infos);
		sign_formatting(infos);
		if (infos->width > infos->len)
			width_formatting(infos);
		write(infos->fd, infos->format, infos->size);
		free(infos->format);
	}
}
