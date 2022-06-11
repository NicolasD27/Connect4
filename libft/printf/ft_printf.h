/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:37:22 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/23 14:23:32 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "../libft.h"
# define ERROR	-1
# define TRUE	1
# define FALSE	0

union			u_type
{
	int					integer;
	unsigned long long	ull;
	long long			ll;
	char				*string;
	void				*address;
	double				dble;
	wint_t				wc;
	wchar_t				*ws;
};

typedef	struct	s_format
{
	char			flags[6];
	int				width;
	int				precision;
	int				length_modif;
	char			conversion;
	int				size;
	union u_type	value;
	int				len;
	char			*format;
	int				written;
	int				fd;
}				t_form;

int				ft_printf(const char *str,
						...) __attribute__((format(printf,1,2)));
int				ft_dprintf(int fd, const char *str,
						...);
int				parse_infos(const char *str, t_form *infos, va_list args);
void			argument_sizing(t_form *infos, va_list args);
void			c_sizing(t_form *infos, va_list args);
void			s_sizing(t_form *infos, va_list args);
void			p_sizing(t_form *infos, va_list args);
void			wide_c_sizing(t_form *infos, va_list args);
void			di_sizing(t_form *infos, va_list args);
void			unsigned_sizing(t_form *infos, va_list args);
void			n_conv(t_form *infos, va_list args);
void			f_sizing(t_form *infos, va_list args);
void			float_calculation(t_form *infos);
/*
**	Formatting functions
*/
void			width_formatting(t_form *infos);
void			int_precision_formatting(t_form *infos);
void			sign_formatting(t_form *infos);
/*
**	Utilitary functions
*/
void			ft_strcpy(char *dst, char *src, int n);
int				order_calculator(long long nb);
int				unsigned_order(unsigned long long nb, int base);

#endif
