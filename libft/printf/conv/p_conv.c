/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:46:16 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/23 14:22:40 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			p_sizing(t_form *infos, va_list args)
{
	infos->value.address = va_arg(args, void *);
	infos->len = unsigned_order((unsigned long)infos->value.address, 16);
	infos->size = infos->len + 2;
	if (infos->width > infos->size)
		infos->size = infos->width;
	infos->format = malloc(sizeof(char) * (1 + infos->size));
	if (!infos->format)
		infos->size = -1;
	else
	{
		infos->format[infos->size] = 0;
		ft_strcpy(infos->format, "0x", 2);
		ft_ulltoa_base_16((unsigned long)infos->value.address, &infos->format[2]);
		if (infos->width > 2 + infos->len)
			width_formatting(infos);
		write(infos->fd, infos->format, infos->size);
		free(infos->format);
	}
}
