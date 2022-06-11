/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:27:28 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/23 14:22:43 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			s_sizing(t_form *infos, va_list args)
{
	infos->value.string = va_arg(args, char *);
	if (!infos->value.string)
		infos->value.string = "(null)";
	infos->len = ft_strlen(infos->value.string);
	if (infos->precision < infos->len && infos->precision != -1)
		infos->len = infos->precision;
	infos->size = infos->len;
	if (infos->width > infos->size)
		infos->size = infos->width;
	infos->format = malloc(sizeof(char) * (1 + infos->size));
	if (!infos->format)
		infos->size = -1;
	else
	{
		infos->format[infos->size] = 0;
		ft_strcpy(&infos->format[0], &infos->value.string[0], infos->len);
		if (infos->width > infos->len)
			width_formatting(infos);
		write(infos->fd, infos->format, infos->size);
		free(infos->format);
	}
}
