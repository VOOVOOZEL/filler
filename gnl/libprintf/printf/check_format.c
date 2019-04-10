/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:28:37 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/03/07 19:30:48 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_conv_type(char **format, t_flags *f, t_length *l)
{
	if (**format == 'L')
	{
		l->lll = 1;
		(*format)++;
	}
	if (**format != 's' && **format != 'd' && **format != 'i' &&
		**format != 'o' && **format != 'p' && **format != 'u' &&
		**format != 'x' && **format != 'X' && **format != 'c' &&
		**format != 'e' && **format != '%' && **format != 'n' &&
		**format != 'U' && **format != 'D' && **format != 'O' &&
		**format != 'S' && **format != 'C' && **format != 'G' &&
		**format != 'E' && **format != 'f' && **format != 'F')
		return (0);
	f->conv = **format;
	return (1);
}

int		ft_check_minwidth(char **format, va_list *ap, t_flags *f)
{
	int i;

	if (f->star == 1)
	{
		f->star--;
		ft_star(ap, f);
		return (1);
	}
	i = ft_atoi(*format);
	*format += ft_count_num(*format);
	if (i > 0)
	{
		f->min_width = i;
		return (1);
	}
	return (0);
}

int		ft_check_precision(va_list *ap, char **format, t_flags *f)
{
	if (**format == '.')
	{
		*format += 1;
		if (**format == '*')
		{
			f->precision = (int)va_arg(*ap, intmax_t);
			if (f->precision < 0)
				f->precision = -1;
			*format += 1;
			return (1);
		}
		else if (f->star != 1)
		{
			f->precision = ft_atoi(*format);
			*format += ft_count_num(*format);
			if (f->precision < 0)
				return (0);
		}
		return (1);
		f->precision = -1;
	}
	return (0);
}

int		ft_check_t_length(char **f, t_length *l)
{
	if (**f == 'h')
	{
		ft_set_h(f, l);
		return (1);
	}
	else if (**f == 'l')
	{
		(*f)++;
		if (**f == 'l')
			l->ll = 1;
		else
			l->l = 1;
		return (1);
	}
	else if (**f == 'j' || **f == 'z')
	{
		if (**f == 'j')
			l->j = 1;
		else if (**f == 'z')
			l->z = 1;
		(*f)++;
		return (1);
	}
	l->none = 1;
	return (0);
}

char	*ft_check_format(char **format, va_list *ap, t_flags *f, t_length *l)
{
	*format += 1;
	if (!**format)
		return (NULL);
	while (!ft_check_conv_type(format, f, l))
	{
		if (ft_check_flag(format, f))
			continue ;
		else if (ft_check_minwidth(format, ap, f))
			continue ;
		else if (ft_check_precision(ap, format, f))
			continue ;
		else if (ft_check_t_length(format, l))
			continue ;
		else
			break ;
	}
	ft_check_t_length(format, l);
	if (!ft_check_conv_type(format, f, l))
		return (ft_invalid(format, f));
	return (ft_build(ap, f, l));
}
