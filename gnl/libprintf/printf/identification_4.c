/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identification_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:30:25 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/03/07 20:30:26 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pe_long(va_list *ap, t_flags *f)
{
	union u_data	type;
	char			*s;

	type.ld = (long double)va_arg(*ap, double);
	if (type.ld == 0.0 && f->precision == 0)
		return (ft_strnew(0));
	if (f->precision == -1)
		f->precision = 6;
	s = ft_itoa_exp(type.ld, f->precision);
	if (f->conv == 'E')
		ft_toupper_s(s);
	return (s);
}

char	*ft_pf_long(va_list *ap, t_flags *f)
{
	union u_data	type;
	char			*s;

	type.ld = (long double)va_arg(*ap, double);
	if (type.ld == 0.0 && f->precision == 0)
		return (ft_strnew(0));
	if (f->precision == -1)
		f->precision = 6;
	s = ft_itoa_double(type.ld, f->precision);
	return (s);
}

char	*ft_pg_long(va_list *ap, t_flags *f)
{
	union u_data	type;
	char			*s;

	type.ld = (long double)va_arg(*ap, double);
	if (type.ld == 0.0 && f->precision == 0)
		return (ft_strnew(0));
	if (f->precision == -1)
		f->precision = 6;
	s = ft_itoa_double_g(type.ld, f->precision);
	if (f->conv == 'G')
		ft_toupper_s(s);
	return (s);
}
