/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:35:18 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/01/04 15:23:36 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(const int fd, char *tmp)
{
	char			*buf;
	char			*to_del;
	int				read_bit;
	int				len;

	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	buf[BUFF_SIZE] = '\0';
	while ((read_bit = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (tmp != NULL)
		{
			to_del = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		tmp = ft_strjoin(to_del, buf);
		len = (ft_strlen(to_del) + read_bit);
		tmp[len] = '\0';
		ft_strdel(&to_del);
		if (ft_strchr(tmp, '\n') != NULL)
			break ;
	}
	ft_strdel(&buf);
	return (tmp);
}

char	*ft_return_next_line(char *tmp, char *rest)
{
	char			*tmp_lick;

	tmp_lick = tmp;
	tmp = ft_strjoin(tmp_lick, rest);
	ft_strdel(&tmp_lick);
	return (tmp);
}

int		ft_return_line(t_list *cur_lst, int fd, char **line)
{
	char			*rest;
	char			*tmp;
	int				i;

	i = 0;
	rest = cur_lst->content;
	tmp = ft_strnew(0);
	if (rest != NULL)
		tmp = ft_return_next_line(tmp, rest);
	if (rest == NULL || ft_strchr(rest, '\n') == NULL)
		tmp = ft_read_file(fd, tmp);
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[0] == '\0')
	{
		ft_strdel(&tmp);
		return (0);
	}
	*line = ft_strsub(tmp, 0, i);
	free(cur_lst->content);
	cur_lst->content = ft_strdup((tmp + i + (ft_strchr(tmp, 10) == 0 ? 0 : 1)));
	ft_strdel(&tmp);
	return (1);
}

void	ft_is_fd(t_list **begin_list, t_list **cur_lst, int fd)
{
	if (*begin_list == NULL)
	{
		*begin_list = ft_lstnew(NULL, 0);
		(*begin_list)->content_size = (size_t)fd;
		*cur_lst = *begin_list;
		return ;
	}
	*cur_lst = *begin_list;
	while (*cur_lst)
	{
		if ((int)(*cur_lst)->content_size == fd)
			return ;
		*cur_lst = (*cur_lst)->next;
	}
	*cur_lst = ft_lstnew(NULL, 0);
	(*cur_lst)->content_size = (size_t)fd;
	ft_lstadd(begin_list, *cur_lst);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*begin_list;
	t_list			*cur_lst;

	if (!line || BUFF_SIZE < 1 || (read(fd, "", 0)) < 0)
		return (-1);
	ft_is_fd(&begin_list, &cur_lst, fd);
	if (ft_return_line(cur_lst, fd, line) == 1)
		return (1);
	return (0);
}
