/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 11:30:30 by pcharton          #+#    #+#             */
/*   Updated: 2020/09/04 14:03:14 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_flags(const char *str, t_form *infos)
{
	int		i;
	int		res;

	i = 0;
	while ((str[i] == '#' || str[i] == ' ' || str[i] == '+' || str[i] == '-'
			|| str[i] == '0') && i < 5)
	{
		infos->flags[i] = str[i];
		i++;
	}
	res = i;
	while (i < 6)
	{
		infos->flags[i] = 0;
		i++;
	}
	return (res);
}

static int	parse_number(const char *str, int *infos, va_list args)
{
	int		i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		*infos = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	else if (str[i] == '*')
	{
		*infos = va_arg(args, int);
		i++;
	}
	else
		*infos = 0;
	return (i);
}

static int	parse_length_modifiers(const char *str, t_form *infos)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	while (str[i] == 'l' || str[i] == 'h')
	{
		if (str[i] == 'l')
			tmp++;
		else
			tmp--;
		i++;
	}
	infos->length_modif = tmp;
	return (i);
}

static void	correct_neg_input(t_form *infos)
{
	int		i;

	i = 0;
	if (infos->width < 0)
	{
		while (infos->flags[i] && infos->flags[i] != '-' && i < 4)
			i++;
		infos->flags[i] = '-';
		infos->width *= -1;
	}
	if (infos->precision < -1)
		infos->precision = -1;
}

int			parse_infos(const char *str, t_form *infos, va_list args)
{
	int		i;

	i = 1;
	i += parse_flags(&str[i], infos);
	i += parse_number(&str[i], &infos->width, args);
	if (str[i] == '.')
	{
		i++;
		i += parse_number(&str[i], &infos->precision, args);
	}
	else
		infos->precision = -1;
	i += parse_length_modifiers(&str[i], infos);
	infos->conversion = str[i++];
	correct_neg_input(infos);
	argument_sizing(infos, args);
	if (infos->size != -1)
		infos->written += infos->size;
	else
		infos->written = 0;
	return (i);
}
