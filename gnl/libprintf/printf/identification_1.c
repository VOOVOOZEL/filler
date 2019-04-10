/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identification_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:24:22 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/03/07 20:24:24 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pc(va_list *ap, t_flags *f, t_length *l)
{
	union u_data	type;
	char			*s;

	if ((l->l == 1 && f->conv == 'c') || f->conv == 'C')
	{
		type.wi = va_arg(*ap, wint_t);
		if (!type.wi)
		{
			f->s_size++;
			return (ft_strnew(1));
		}
		s = ft_wprint(type.wi);
		return (s);
	}
	type.i = va_arg(*ap, intmax_t);
	if (!type.i)
	{
		f->s_size++;
		f->min_width -= 1;
		return (ft_strnew(1));
	}
	s = ft_strnew(1);
	s[0] = type.i;
	return (s);
}

char	*ft_pd(va_list *ap, t_flags *f, t_length *l)
{
	union u_data	type;
	intmax_t		i;
	char			*s;

	if (f->conv == 'D')
		l->l = 1;
	type.i = ft_conv_len(ap, l);
	if (type.i == 0 && f->precision == 0)
		return (ft_strnew(0));
	else if (type.i == 0)
	{
		s = ft_strnew(1);
		s[0] = '0';
	}
	else
		s = ft_itoa_signed(type.i);
	i = ft_strlen(s);
	if (i <= f->precision)
	{
		if (type.i < 0)
			f->precision += 1;
		s = ft_precision(s, f->precision - i);
	}
	return (s);
}

char	*ft_po(va_list *ap, t_flags *f, t_length *l)
{
	union u_data	type;
	intmax_t		i;
	char			*s;
	char			*tmp;

	(f->conv == 'O') ? l->l = 1 : l->l;
	type.u = ft_conv_unsigned(ap, l);
	if (type.u == 0 && f->precision == 0 && f->hash != 1)
		return (ft_strnew(0));
	else if (type.u == 0)
	{
		s = ft_strnew(1);
		s[0] = '0';
		return (s);
	}
	(f->hash == 1) ? f->precision-- : f->precision;
	s = ft_itoa_unsigned(type.u, 8);
	i = ft_strlen(s);
	s = (i < f->precision) ? ft_precision(s, f->precision - i) : s;
	if (f->hash == 1)
	{
		tmp = s;
		s = ft_strjoin("0", tmp);
	}
	return (s);
}

char	*ft_px(va_list *ap, t_flags *f, t_length *l)
{
	union u_data	type;
	intmax_t		i;
	char			*s;
	char			*tmp;

	type.u = ft_conv_unsigned(ap, l);
	if (type.u == 0 && f->precision == 0)
		return (ft_strnew(0));
	else if (type.u == 0)
	{
		s = ft_strdup("0");
		return (s);
	}
	s = ft_itoa_unsigned(type.u, 16);
	i = ft_strlen(s);
	s = (i < f->precision) ? ft_precision(s, f->precision - i) : s;
	if (f->hash == 1)
	{
		tmp = s;
		s = ft_strjoin("0x", tmp);
		free(tmp);
	}
	if (f->conv == 'X')
		ft_toupper_s(s);
	return (s);
}
