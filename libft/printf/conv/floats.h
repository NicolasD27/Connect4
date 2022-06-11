/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 10:39:05 by pcharton          #+#    #+#             */
/*   Updated: 2020/09/05 17:04:22 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATS_H
# define FLOATS_H
# include "../ft_printf.h"

typedef int				t_bool;

typedef struct			s_float
{
	unsigned long long	integer;
	double				decimal;
	t_bool				sign;
	int					integer_len;
	int					tmp;
	long long			bin_rpz;
	char				*limits;
}						t_float;

int						check_floats(t_form *infos, t_float *extract);
void					double_extraction(t_form *infos, double value);
int						put_decimal_in_str(t_form *infos, t_float extract);
void					start_rounding(char *str, t_form *infos);
void					advanced_rounding(t_form *infos);
int						sizing_sign(double value, t_form *infos);
void					float_width_formatting(t_form *infos, t_float *extract);
void					resize_buffer(t_form *infos);
int						f_adding_sign(t_form *infos);
#endif
