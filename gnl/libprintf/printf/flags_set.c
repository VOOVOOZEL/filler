/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:50:12 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/03/07 19:50:13 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_flag(char **format, t_flags *f)
{
	int i;

	i = ft_count_flags(*format);
	if (i == 0)
		return (0);
	while (i-- > 0)
	{
		if (**format == '+')
			f->plus = 1;
		else if (**format == '-')
			f->minus = 1;
		else if (**format == '0')
			f->zero = 1;
		else if (**format == '#')
			f->hash = 1;
		else if (**format == ' ')
			f->space = 1;
		else if (**format == '*')
			f->star = 1;
		else
			return (0);
		*format += 1;
	}
	return (1);
}

char	*ft_flags(char *s, t_flags *f)
{
	if (f->space == 1)
		s = ft_space(s, f);
	if (f->zero == 1)
		ft_zero_fl(s, '0', f);
	if (!s)
		return (NULL);
	return (s);
}

void	ft_reset(t_flags *f, t_length *l)
{
	f->plus = 0;
	f->minus = 0;
	f->hash = 0;
	f->space = 0;
	f->zero = 0;
	f->star = 0;
	f->s_size = 0;
	f->precision = -1;
	f->min_width = -1;
	f->conv = 0;
	l->none = 0;
	l->hh = 0;
	l->h = 0;
	l->l = 0;
	l->ll = 0;
	l->j = 0;
	l->z = 0;
}
