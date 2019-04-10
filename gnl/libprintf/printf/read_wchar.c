/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:50:31 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/03/07 19:50:33 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_count_wsize(unsigned warg)
{
	int size;

	size = 0;
	if (warg < 0x80)
		size++;
	else if (warg <= 0x7FF)
		size += 2;
	else if (warg <= 0xFFFF)
		size += 3;
	else if (warg <= 0x10FFFF)
		size += 4;
	return (size);
}

char	*ft_wprint(wint_t warg)
{
	char *s;

	if (warg < (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
	{
		s = ft_strnew(1);
		s[0] = (unsigned char)warg;
	}
	else if (warg <= 0x7FF)
	{
		s = ft_strnew(2);
		s[0] = (unsigned char)((warg >> 6) | 0xC0);
		s[1] = (unsigned char)((warg & 0x3F) | 0x80);
	}
	else
		return (ft_wprint_1(warg));
	return (s);
}

char	*ft_wprint_1(wint_t warg)
{
	char *s;

	s = NULL;
	if (warg <= 0xFFFF)
	{
		s = ft_strnew(3);
		s[0] = (unsigned char)(((warg >> 12)) | 0xE0);
		s[1] = (unsigned char)(((warg >> 6) & 0x3F) | 0x80);
		s[2] = (unsigned char)((warg & 0x3F) | 0x80);
	}
	else if (warg <= 0x10FFFF)
	{
		s = ft_strnew(4);
		s[0] = (unsigned char)(((warg >> 18)) | 0xF0);
		s[1] = (unsigned char)(((warg >> 12) & 0x3F) | 0x80);
		s[2] = (unsigned char)(((warg >> 6) & 0x3F) | 0x80);
		s[3] = (unsigned char)((warg & 0x3F) | 0x80);
	}
	return (s);
}
