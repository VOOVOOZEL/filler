/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:45:30 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/04/10 15:45:32 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	ft_encircling_point(t_filler *f, int y, int x)
{
	int	cur;

	cur = f->n_map[y][x];
	if (f->n_map[y][x] < 0)
		return ;
	if (y != 0 && f->n_map[y - 1][x] > cur)
		f->n_map[y - 1][x] = cur + 1;
	if (y < f->hight - 1 && f->n_map[y + 1][x] > cur)
		f->n_map[y + 1][x] = cur + 1;
	if (x != 0 && f->n_map[y][x - 1] > cur)
		f->n_map[y][x - 1] = cur + 1;
	if (y < f->width - 1 && f->n_map[y][x + 1] > cur)
		f->n_map[y][x + 1] = cur + 1;
	if (y != 0 && x != 0 && f->n_map[y - 1][x - 1] > cur)
		f->n_map[y - 1][x - 1] = cur + 1;
	if (y != 0 && x < f->width - 1 && f->n_map[y - 1][x + 1] > cur)
		f->n_map[y - 1][x + 1] = cur + 1;
	if (y < f->hight - 1 && x != 0 && f->n_map[y + 1][x - 1] > cur)
		f->n_map[y + 1][x - 1] = cur + 1;
	if (y < f->hight - 1 && x < f->width - 1 && f->n_map[y + 1][x + 1] > cur)
		f->n_map[y + 1][x + 1] = cur + 1;
}

int		ft_get_sum(t_filler *f, int y, int x)
{
	int	i;
	int	j;
	int sum;

	sum = 0;
	i = -1;
	while (++i < f->token.hight)
	{
		j = -1;
		while (++j < f->token.width)
			if (f->token.piece[i][j] == '*')
			{
				if (f->n_map[y + i][x + j] == -1)
					sum += MAX_POINT;
				else
					sum += f->n_map[y + i][x + j];
			}
	}
	return (sum);
}

void	ft_set_bcoor(t_filler *f, int i, int j, t_pos *mn)
{
	int		tmp;

	tmp = ft_get_sum(f, i, j);
	if (mn->min_sum == -1 || mn->min_sum > tmp)
	{
		mn->min_sum = tmp;
		*mn = (t_pos){j, i, mn->min_sum};
	}
}

void	ft_get_state(t_filler *f, t_state *st, int i, int j)
{
	int	k;
	int	l;

	k = -1;
	while (++k < f->token.hight)
	{
		l = -1;
		while (++l < f->token.width)
		{
			if (f->token.piece[k][l] == '*' && f->map[i + k][j + l] == '.')
				st->is_dot = 1;
			else if (f->token.piece[k][l] == '*'
			&& f->map[i + k][j + l] == f->player_sym)
				st->is_ps = 1;
			else if (f->token.piece[k][l] == '*'
			&& f->map[i + k][j + l] == f->enemy_sym)
				st->is_enemy = 1;
		}
	}
}

void	ft_find_place(t_filler *f)
{
	int		i;
	int		j;
	int		tmp;
	t_pos	mn;
	t_state	st;

	mn = (t_pos){0, 0, -1};
	i = -1;
	while (++i < f->hight - f->token.hight)
	{
		j = -1;
		while (++j < f->width - f->token.width)
		{
			st = (t_state){0, 0, 0};
			ft_get_state(f, &st, i, j);
			if (st.is_ps && st.is_dot && !st.is_enemy)
			{
				tmp = ft_get_sum(f, i, j);
				ft_set_bcoor(f, i, j, &mn);
			}
		}
	}
	ft_printf("%d %d\n", mn.y, mn.x);
}
