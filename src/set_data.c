/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:45:04 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/04/10 15:45:06 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	ft_get_token(t_filler *f)
{
	int		i;
	char	*line;

	i = -1;
	f->token.piece = (char**)malloc(sizeof(char*) * f->token.hight);
	ft_bzero(f->token.piece, f->token.hight * sizeof(char*));
	while (++i < f->token.hight)
		f->token.piece[i] = (char*)malloc(sizeof(char) * f->token.width);
	i = -1;
	while (++i < f->token.hight)
	{
		get_next_line(0, &line);
		f->token.piece[i] = ft_strdup(line);
		ft_strdel(&line);
	}
}

void	ft_get_map(t_filler *f)
{
	int		i;
	int		j;
	char	*line;
	char	**tmp;

	i = -1;
	while (++i < f->hight)
	{
		j = -1;
		get_next_line(0, &line);
		tmp = ft_strsplit(line, ' ');
		while (++j < f->width)
		{
			f->map[i][j] = tmp[1][j];
			if (f->map[i][j] == f->player_sym)
				f->n_map[i][j] = -1;
			else if (f->map[i][j] == f->enemy_sym)
				f->n_map[i][j] = 0;
			else
				f->n_map[i][j] = MAX_POINT;
		}
		free(tmp[0]);
		free(tmp[1]);
		ft_strdel(&line);
	}
}

void	ft_get_player(char *line, t_filler *f)
{
	if (!line[10] && (line[10] != 1 && line[10] != 2))
	{
		ft_printf("bad player");
		ft_strdel(&line);
		exit(1);
	}
	f->player = line && line[10] == '1' ? 1 : 2;
	f->player_sym = line && line[10] == '1' ? 'O' : 'X';
	f->enemy_sym = line && line[10] == '1' ? 'X' : 'O';
}

void	ft_get_size(char *line, int *hight, int *width)
{
	char		**tmp;
	int			i;

	i = -1;
	tmp = ft_strsplit(line, ' ');
	*hight = ft_atoi(tmp[1]);
	*width = ft_atoi(tmp[2]);
	while (++i < 3)
		free(tmp[i]);
}
