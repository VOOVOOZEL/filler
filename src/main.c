/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:45:18 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/04/10 15:45:22 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	ft_make_heat_map(t_filler *f)
{
	int i;
	int	j;
	int	n;

	n = f->hight > f->width ? f->hight : f->width;
	while (n--)
	{
		i = -1;
		while (++i < f->hight)
		{
			j = -1;
			while (++j < f->width)
				ft_encircling_point(f, i, j);
		}
	}
}

void	ft_create_maps(t_filler *f)
{
	int	i;

	f->map = (char**)malloc(sizeof(char*) * f->hight);
	i = -1;
	ft_bzero(f->map, f->hight * sizeof(char*));
	while (++i < f->hight)
		f->map[i] = (char*)malloc(sizeof(char) * f->width);
	f->n_map = (int**)malloc(sizeof(int*) * f->hight);
	i = -1;
	ft_bzero(f->n_map, f->hight * sizeof(int*));
	while (++i < f->hight)
		f->n_map[i] = (int*)malloc(sizeof(int) * f->width);
}

void	ft_free_maps(t_filler *f)
{
	int i;

	i = -1;
	while (++i < f->hight)
		free(f->map[i]);
	i = -1;
	while (++i < f->hight)
		free(f->n_map[i]);
}

void	ft_set_base(t_filler *f)
{
	char		*line;

	get_next_line(0, &line);
	ft_get_player(line, f);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_get_size(line, &f->hight, &f->width);
	ft_strdel(&line);
	ft_create_maps(f);
}

int		main(void)
{
	char		*line;
	t_filler	f;

	ft_set_base(&f);
	while (1)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
		ft_get_map(&f);
		ft_make_heat_map(&f);
		get_next_line(0, &line);
		ft_get_size(line, &f.token.hight, &f.token.width);
		ft_strdel(&line);
		ft_get_token(&f);
		ft_find_place(&f);
		if (get_next_line(0, &line) < 1)
		{
			ft_free_maps(&f);
			exit(0);
		}
		if (line)
			ft_strdel(&line);
	}
}
