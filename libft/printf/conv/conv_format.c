/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:58:23 by pcharton          #+#    #+#             */
/*   Updated: 2020/09/04 14:08:09 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		width_formatting(t_form *infos)
{
	if (((ft_strchr(infos->flags, '-')) == NULL) && infos->precision == -1
		&& (ft_strchr(infos->flags, '0')) != NULL)
	{
		ft_memmove(&infos->format[infos->size - infos->len], &infos->format[0],
				infos->len);
		ft_memset(&infos->format[0], '0', infos->size - infos->len);
	}
	else if ((ft_strchr(infos->flags, '-')) != NULL)
	{
		if (infos->precision > infos->len)
			ft_memset(&infos->format[infos->precision], ' ',
					infos->size - infos->precision);
		else
			ft_memset(&infos->format[infos->len], ' ',
					infos->size - infos->len);
	}
	else if ((ft_strchr(infos->flags, '-')) == NULL)
	{
		ft_memmove(&infos->format[infos->size - infos->len], &infos->format[0],
			infos->len);
		if (infos->precision > infos->len)
			ft_memset(&infos->format[0], ' ', infos->size - infos->precision);
		else
			ft_memset(&infos->format[0], ' ', infos->size - infos->len);
	}
}

void		int_precision_formatting(t_form *infos)
{
	if (infos->precision > infos->len)
	{
		ft_memmove(&infos->format[infos->precision - infos->len],
				&infos->format[0], infos->len);
		ft_memset(&infos->format[0], '0', infos->precision - infos->len);
		infos->len = infos->precision;
	}
	else
		return ;
}

void		sign_formatting(t_form *infos)
{
	if (infos->value.ll < 0 || (ft_strchr(infos->flags, '+'))
		|| (ft_strchr(infos->flags, ' ')))
	{
		ft_memmove(&infos->format[1], &infos->format[0],
				infos->len);
		if (infos->value.ll < 0)
			infos->format[0] = '-';
		else if ((ft_strchr(infos->flags, '+')) && infos->value.ll > 0)
			infos->format[0] = '+';
		else if ((ft_strchr(infos->flags, ' ')) && infos->value.ll > 0)
			infos->format[0] = ' ';
		if (infos->precision > infos->len)
			infos->precision++;
		else
			infos->len++;
	}
}
