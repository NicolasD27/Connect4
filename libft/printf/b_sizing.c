/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sizing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 13:44:15 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/23 09:45:04 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			argument_sizing(t_form *infos, va_list args)
{
	if (infos->conversion == 'c' || infos->conversion == '%')
		c_sizing(infos, args);
	else if (infos->conversion == 's')
		s_sizing(infos, args);
	else if (infos->conversion == 'p')
		p_sizing(infos, args);
	else if (infos->conversion == 'd' || infos->conversion == 'i')
		di_sizing(infos, args);
	else if (infos->conversion == 'u' || infos->conversion == 'x'
			|| infos->conversion == 'X')
		unsigned_sizing(infos, args);
	else if (infos->conversion == 'n')
		n_conv(infos, args);
	else if (infos->conversion == 'f')
		f_sizing(infos, args);
}
