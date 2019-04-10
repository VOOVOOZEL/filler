/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:47:13 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/03/07 19:49:49 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_invalid(char **format, t_flags *f)
{
	char *s;

	s = ft_strnew(1);
	s[0] = **format;
	s = ft_min_width(s, f);
	return (ft_flags(s, f));
}

void	ft_star(va_list *ap, t_flags *f)
{
	int width;

	width = va_arg(*ap, intmax_t);
	if (width < 0)
	{
		f->minus = 1;
		f->min_width = width * -1;
	}
	else
		f->min_width = width;
}

void	place_zero(char *s, char c, t_flags *f)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '-' || s[i] == '+')
	{
		if (f->space == 1 && s[0] == ' ')
			i++;
		if (s[i] == '-' || s[i] == '+')
		{
			s[0] = s[i];
			if (i > 0)
				s[i] = c;
		}
		else if (s[i] == ' ')
			s[i] = c;
		i++;
	}
	if ((s[i + 1] == 'x' || s[i + 1] == 'X') && f->hash == 1)
	{
		s[1] = s[i + 1];
		if ((i + 1) != 1)
			s[i + 1] = c;
	}
}

void	ft_zero_fl(char *s, char c, t_flags *f)
{
	if (f->precision >= 0 && (f->conv == 'd' || f->conv == 'D' || f->conv == 'i'
		|| f->conv == 'o' || f->conv == 'O' || f->conv == 'u' || f->conv == 'U'
		|| f->conv == 'x' || f->conv == 'X'))
		return ;
	place_zero(s, c, f);
}

char	*ft_space(char *s, t_flags *f)
{
	int		i;
	char	*p;

	if (f->plus == 1)
		return (s);
	i = 0;
	while (s[i] == ' ')
		i++;
	if (i == 0 && s[i] != '-' && (f->conv == 'a' || f->conv == 'A' ||
		f->conv == 'd' || f->conv == 'e' || f->conv == 'E' ||
		f->conv == 'f' || f->conv == 'F' || f->conv == 'g' ||
		f->conv == 'G' || f->conv == 'i'))
	{
		p = ft_strjoin(" ", s);
		free(s);
		return (p);
	}
	else
		return (s);
}
