/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double_g.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:37:34 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/03/07 20:38:19 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*pure_s(long double nbr, int k)
{
	int			count;
	uintmax_t	n;

	if (nbr == 0.0)
		return ("0");
	if (nbr < 0)
		nbr *= -1;
	n = (uintmax_t)nbr;
	if (n == 0)
	{
		n = (uintmax_t)nbr * ft_power(10, k - 1);
		count = ft_countnumber(n, 10);
		if (count <= k)
			return (ft_itoa_double(nbr, k));
		return (ft_itoa_exp(nbr, k));
	}
	count = ft_countnumber(n, 10);
	if (count <= k)
		return (ft_itoa_double(nbr, k - count));
	return (ft_itoa_exp(nbr, k - 1));
}

char		*ft_itoa_double_g(long double nbr, int k)
{
	char	*tmp;
	char	*s;
	int		i;
	int		dot;

	tmp = pure_s(nbr, k);
	i = ft_strlen(tmp);
	dot = 0;
	while (tmp)
		if (tmp[dot++] == '.')
			break ;
	if (dot == i)
		return (tmp);
	while (i-- > dot)
	{
		if (tmp[i] != '0')
			break ;
	}
	if (i == dot + 1)
		i = dot;
	s = ft_strsub(tmp, 0, i + 1);
	if (tmp)
		free(tmp);
	return (s);
}
