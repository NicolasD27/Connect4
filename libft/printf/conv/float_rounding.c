/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_rounding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 10:55:29 by pcharton          #+#    #+#             */
/*   Updated: 2020/09/06 13:47:53 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "floats.h"
#include "../ft_printf.h"

int			sizing_sign(double value, t_form *infos)
{
	unsigned long long	sign;

	ft_memcpy(&sign, &value, 8);
	sign >>= 63;
	if (sign)
		return (1);
	else if ((ft_strchr(infos->flags, ' ') || ft_strchr(infos->flags, '+'))
			&& sign == 0)
		return (1);
	else
		return (0);
}

void		start_rounding(char *str, t_form *infos)
{
	int		i;

	i = 0;
	while (str[i] == '9')
	{
		str[i] = '0';
		i--;
	}
	if (str[i] == '.')
		i--;
	while (str[i] == '9')
	{
		str[i] = '0';
		i--;
	}
	if (str[i] >= '0' && str[i] <= '8')
	{
		str[i] += 1;
	}
	else
		advanced_rounding(infos);
}

void		advanced_rounding(t_form *infos)
{
	int		size;
	char	*ptr;
	t_bool	sign;

	size = infos->len + infos->precision + 1;
	sign = sizing_sign(infos->value.dble, infos);
	size += sign;
	if (infos->precision > 0 || ft_strchr(infos->flags, '#'))
		size++;
	if (size > infos->size)
	{
		ptr = malloc(sizeof(char) * (1 + size));
		ptr[sign] = '1';
		ft_memmove(&ptr[sign + 1], &infos->format[sign], size);
		free(infos->format);
		infos->format = ptr;
		infos->size = size;
	}
	else
		ft_memmove(&infos->format[sign + 1], &infos->format[sign], infos->size);
}
