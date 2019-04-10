/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:31:20 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/03/07 20:31:22 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_format(char **format, va_list *ap, t_flags *f, t_length *l)
{
	char	*tmp;

	if (!(tmp = ft_check_format(format, ap, f, l)) && !**format)
		return (0);
	if (!f->conv && !**format)
		return (0);
	f->s_size += ft_strlen(tmp);
	write(1, tmp, f->s_size);
	f->total_size += f->s_size;
	if (*tmp)
		free(tmp);
	return (1);
}

int		ft_readformat(char **format, va_list ap)
{
	t_flags		f;
	t_length	l;

	f.total_size = 0;
	while (ft_strlen(*format) > 0)
	{
		ft_reset(&f, &l);
		if (**format == '%')
		{
			if (!print_format(format, (va_list*)ap, &f, &l))
				return (f.total_size);
		}
		else
		{
			f.total_size++;
			write(1, *format, 1);
		}
		if (*format)
			*format += 1;
	}
	return (f.total_size);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		i;

	if (!format || !*format)
		return (0);
	va_start(ap, format);
	i = ft_readformat((char**)&format, ap);
	va_end(ap);
	return (i);
}
