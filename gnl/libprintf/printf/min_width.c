/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:51:22 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/03/07 19:52:23 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_passiv(t_flags *f, char *s)
{
	if (f->star == 1)
		write(1, s, 1);
	if (f->conv == 'c' || f->conv == 'C')
		f->s_size--;
	f->total_size++;
}

char	*ft_extend_s(t_flags *f, char *s, int k, char left)
{
	char	*tmp;

	if (left == '+')
	{
		while (k-- > 0)
		{
			tmp = s;
			s = ft_strjoin(" ", tmp);
			if (*tmp)
				free(tmp);
		}
		return (s);
	}
	if (!ft_strlen(s))
		ft_passiv(f, s);
	while (k-- > 0)
	{
		tmp = s;
		s = ft_strjoin(tmp, " ");
		if (*tmp)
			free(tmp);
	}
	return (s);
}

char	*ft_min_width(char *s, t_flags *f)
{
	intmax_t	i;
	char		*tmp;

	i = ft_strlen(s);
	if ((f->conv == 'd' || f->conv == 'i' || f->conv == 'e' ||
		f->conv == 'E' || f->conv == 'f' || f->conv == 'F' ||
		f->conv == 'g' || f->conv == 'G') &&
		i > 0 && s[0] != '-' && f->plus == 1)
	{
		tmp = s;
		s = ft_strjoin("+", tmp);
		free(tmp);
		f->min_width -= 1;
	}
	if (i > f->min_width)
		return (s);
	if (f->minus == 1)
		return (ft_extend_s(f, s, f->min_width - i, '-'));
	return (ft_extend_s(f, s, f->min_width - i, '+'));
}
