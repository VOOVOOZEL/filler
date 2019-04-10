/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:50:51 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/03/07 19:50:52 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include <wchar.h>
# include "../libft/libft.h"
# include <stdio.h>

union			u_data
{
	intmax_t	i;
	uintmax_t	u;
	wchar_t		*ws;
	wint_t		wi;
	double		d;
	long double	ld;
	char		*s;
}				t_data;

typedef struct	s_flags
{
	int			plus;
	int			minus;
	int			hash;
	int			space;
	int			zero;
	int			star;
	int			precision;
	int			min_width;
	char		conv;
	uintmax_t	s_size;
	uintmax_t	total_size;
}				t_flags;

typedef struct	s_length
{
	int			none;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			lll;
}				t_length;

int				ft_printf(const char *restrict format, ...);
int				print_format(char **format, va_list *ap, t_flags *f,
														t_length *l);
int				ft_readformat(char **format, va_list ap);
char			*ft_precision(char *tmp, int n);
char			*ft_pd(va_list *ap, t_flags *f, t_length *l);
char			*ft_pc(va_list *ap, t_flags *f, t_length *l);
char			*ft_po(va_list *ap, t_flags *f, t_length *l);
char			*ft_px(va_list *ap, t_flags *f, t_length *l);
char			*ft_pu(va_list *ap, t_flags *f, t_length *l);
char			*ft_ps(va_list *ap, t_flags *f, t_length *l);
char			*ft_pe(va_list *ap, t_flags *f, t_length *l);
char			*ft_pf(va_list *ap, t_flags *f, t_length *l);
char			*ft_pg(va_list *ap, t_flags *f, t_length *l);
char			*ft_pe_long(va_list *ap, t_flags *f);
char			*ft_pf_long(va_list *ap, t_flags *f);
char			*ft_pg_long(va_list *ap, t_flags *f);
char			*ft_pws(va_list *ap, t_flags *f);
char			*ft_pp(va_list *ap, t_flags *f);
char			*ft_pper(void);

intmax_t		ft_conv_len(va_list *ap, t_length *l);
uintmax_t		ft_conv_unsigned(va_list *ap, t_length *l);

char			*ft_identification(char *p, va_list ap, int precision);

int				ft_count_num(char *p);
int				ft_count_flags(char *p);

int				ft_check_flag(char **format, t_flags *f);
char			*ft_flags(char *s, t_flags *f);
void			ft_reset(t_flags *f, t_length *l);

int				ft_count_wsize(unsigned warg);
char			*ft_wprint(wint_t warg);
char			*ft_wprint_1(wint_t warg);

int				ft_check_conv_type(char **format, t_flags *f, t_length *l);
int				ft_check_minwidth(char **format, va_list *ap, t_flags *f);
int				ft_check_precision(va_list *ap, char **format, t_flags *f);
int				ft_check_t_length(char **f, t_length *l);
char			*ft_check_format(char **format, va_list *ap, t_flags *f,
															t_length *l);

void			ft_zero_fl(char *s, char c, t_flags *f);
void			place_zero(char *s, char c, t_flags *f);
char			*ft_space(char *s, t_flags *f);
void			ft_star(va_list *ap, t_flags *f);

char			*ft_build(va_list *ap, t_flags *f, t_length *l);
char			*ft_min_width(char *s, t_flags *f);
char			*ft_extend_s(t_flags *f, char *s, int k, char left);
void			ft_set_h(char **f, t_length *l);

int				add_len(t_flags *f);
char			*ft_invalid(char **format, t_flags *f);

#endif
