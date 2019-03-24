/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:21:39 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/24 12:57:30 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int	null_check(char **line, char **tab)
{
	if (ft_strlen(*tab) > 0)
	{
		ft_memdel((void **)line);
		*line = ft_strjoin(*tab, "");
		ft_bzero(*tab, ft_strlen(*tab));
		return (1);
	}
	return (0);
}

int	read_next_buffer(int a, char **tab, char **line, char *buf)
{
	int	j;

	j = 0;
	buf[a] = '\0';
	while (buf[j] != '\n' && j < (a - 1))
		j++;
	if (buf[j] == '\n')
	{
		buf[j] = '\0';
		ft_memdel((void **)line);
		*line = ft_strjoin(*tab, buf);
		ft_bzero(*tab, ft_strlen(*tab));
		if (j >= (a - 1))
			*tab = ft_strdup("");
		else
			*tab = ft_strdup(buf + (j + 1));
		return (1);
	}
	return (0);
}

int	chomp_line(char **tab, char **line)
{
	char	*tmp;

	if (!((ft_strchr(*tab, '\n')) == NULL))
	{
		ft_memdel((void **)line);
		tmp = ft_strchr(*tab, '\n');
		*tmp = '\0';
		*line = ft_strdup(*tab);
		tmp++;
		ft_bzero(*tab, ft_strlen(*tab));
		*tab = ft_strjoin(*tab, tmp);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*tab[FD_LIMIT];
	char		*buf;
	int			a;
	int			j;

	a = 0;
	j = 0;
	if (!(tab[fd]))
		tab[fd] = ft_strdup("");
	buf = ft_strnew(BUFF_SIZE + 1);
	if (ft_strlen(tab[fd]) > 0)
		if (chomp_line(&tab[fd], line) == 1)
			return (1);
	while ((a = read(fd, buf, BUFF_SIZE)) >= 0)
	{
		if (a == 0)
			return (null_check(line, &tab[fd]));
		if ((read_next_buffer(a, &tab[fd], line, buf)) == 1)
			return (1);
		tab[fd] = ft_strjoin(tab[fd], buf);
		ft_memset(buf, '\0', BUFF_SIZE);
		free(buf);
		buf = ft_strnew(BUFF_SIZE + 1);
	}
	return (0);
}
