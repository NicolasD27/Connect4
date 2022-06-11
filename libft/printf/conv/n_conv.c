/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:42:06 by pcharton          #+#    #+#             */
/*   Updated: 2020/09/04 14:15:12 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		n_conv2(t_form *infos, va_list args)
{
	long		*big;
	long long	*xbig;

	if (infos->length_modif == 1)
	{
		big = va_arg(args, long *);
		*big = (long)infos->written;
	}
	else if (infos->length_modif == 2)
	{
		xbig = va_arg(args, long long *);
		*xbig = (long long int)infos->written;
	}
}

void			n_conv(t_form *infos, va_list args)
{
	int			*normal;
	signed char	*xsmall;
	short		*small;

	if (infos->length_modif == -2)
	{
		xsmall = va_arg(args, signed char *);
		*xsmall = (signed char)infos->written;
	}
	else if (infos->length_modif == -1)
	{
		small = va_arg(args, short *);
		*small = (short)infos->written;
	}
	else if (infos->length_modif == 1 || infos->length_modif == 2)
		n_conv2(infos, args);
	else
	{
		normal = va_arg(args, int *);
		*normal = infos->written;
	}
}
