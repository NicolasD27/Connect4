/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharton <pcharton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:37:12 by pcharton          #+#    #+#             */
/*   Updated: 2022/05/23 15:18:41 by pcharton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_strcpy(char *dst, char *src, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	write_before_percent(const char **str, t_form *infos)
{
	int			i;

	i = 0;
	while (*(*str + i) != '%')
		i++;
	write(infos->fd, *str, i);
	*str += i;
	infos->written += i;
}

static void	write_end_string(const char **str, t_form *infos)
{
	int			length;

	length = ft_strlen(*str);
	write(infos->fd, *str, length);
	*str += length;
	infos->written += length;
}

int			ft_printf(const char *str, ...)
{
	va_list		args;
	t_form		infos;
	char		*ptr;

	va_start(args, str);
	infos.written = 0;
	infos.fd = STDOUT_FILENO;
	while (*str)
	{
		if ((ptr = ft_strchr(str, '%')) != NULL)
		{
			write_before_percent(&str, &infos);
			str += parse_infos(str, &infos, args);
		}
		else
		{
			if (!*str)
				break ;
			write_end_string(&str, &infos);
		}
	}
	va_end(args);
	return (infos.written);
}

int			ft_dprintf(int fd, const char *str, ...)
{
	va_list		args;
	t_form		infos;
	char		*ptr;

	va_start(args, str);
	infos.written = 0;
	infos.fd = fd;
	while (*str)
	{
		if ((ptr = ft_strchr(str, '%')) != NULL)
		{
			write_before_percent(&str, &infos);
			str += parse_infos(str, &infos, args);
		}
		else
		{
			if (!*str)
				break ;
			write_end_string(&str, &infos);
		}
	}
	va_end(args);
	return (infos.written);
}
