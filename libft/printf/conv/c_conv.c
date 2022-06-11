/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 13:46:51 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/23 09:58:21 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		c_sizing(t_form *infos, va_list args)
{
	if (infos->length_modif == 1)
	{
		wide_c_sizing(infos, args);
		return ;
	}
	if (infos->conversion == '%')
		infos->value.integer = '%';
	else
		infos->value.integer = va_arg(args, int);
	infos->len = 1;
	infos->size = infos->len;
	if (infos->width > infos->size)
		infos->size = infos->width;
	infos->format = malloc(sizeof(char) * (1 + infos->size));
	if (!infos->format)
	{
		infos->written = -1;
		return ;
	}
	infos->format[infos->size] = 0;
	infos->format[0] = (char)infos->value.integer;
	if (infos->width > 1)
		width_formatting(infos);
	write(infos->fd, infos->format, infos->size);
	free(infos->format);
}

void		wide_c_sizing(t_form *infos, va_list args)
{
	infos->value.wc = va_arg(args, wint_t);
	write(infos->fd, &infos->value.wc, sizeof(wint_t));
}
