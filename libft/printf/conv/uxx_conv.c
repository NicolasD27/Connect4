/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uxx_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:13:24 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/23 14:22:48 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned long long	unsigned_length_modif(int lm, va_list args)
{
	unsigned long long	nb;

	if (lm == -2)
		nb = (unsigned char)va_arg(args, unsigned int);
	else if (lm == -1)
		nb = (unsigned short)va_arg(args, unsigned int);
	else if (lm == 1)
		nb = (unsigned long)va_arg(args, unsigned long);
	else if (lm == 2)
		nb = va_arg(args, unsigned long long);
	else
		nb = (unsigned int)va_arg(args, unsigned int);
	return (nb);
}

static void					u_conv(t_form *infos)
{
	ft_ulltoa(infos->value.ull, infos->format);
	int_precision_formatting(infos);
	if (infos->width > infos->len)
		width_formatting(infos);
	write(infos->fd, infos->format, infos->size);
	free(infos->format);
}

static void					str_to_upcase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] -= 32;
		i++;
	}
}

static void					x_conv(t_form *infos)
{
	ft_ulltoa_base_16(infos->value.ull, infos->format);
	int_precision_formatting(infos);
	if (infos->value.ull && ft_strchr(infos->flags, '#'))
	{
		ft_memmove(&infos->format[2], &infos->format[0], infos->len);
		ft_strcpy(&infos->format[0], "0x", 2);
	}
	if (infos->width > infos->len)
		width_formatting(infos);
	if (infos->conversion == 'X')
		str_to_upcase(infos->format);
	write(infos->fd, infos->format, infos->size);
	free(infos->format);
}

void						unsigned_sizing(t_form *infos, va_list args)
{
	infos->value.ull = unsigned_length_modif(infos->length_modif, args);
	if (infos->conversion == 'u')
		infos->len = unsigned_order(infos->value.ull, 10);
	else
		infos->len = unsigned_order(infos->value.ull, 16);
	infos->size = infos->len;
	if (infos->precision > infos->len)
		infos->size = infos->precision;
	if (infos->value.ull && (ft_strchr(infos->flags, '#')))
		infos->size += 2;
	if (infos->width > infos->size)
		infos->size = infos->width;
	infos->format = malloc(sizeof(char) * (1 + infos->size));
	if (!infos->format)
		infos->size = -1;
	else
	{
		infos->format[infos->size] = 0;
		if (infos->conversion == 'u')
			u_conv(infos);
		else
			x_conv(infos);
	}
}
