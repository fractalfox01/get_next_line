/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:05:09 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/21 16:52:33 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"
#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char	*tab[FD_LIMIT];
	char		*buf;
//	char		*tmp;
	int			a;
	int			j;

	a = 0;
	j = 0;
	if (!(tab[fd]))
		tab[fd] = strdup("");
	buf = ft_strnew(BUFF_SIZE + 1);
	if (ft_strlen(tab[fd]) > 0)
	{
		if ((ft_strchr(tab[fd], '\n')))
			printf("found newline in tab[fd]\n");
	}
	while ((a = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[a] = '\0';
		while (buf[j] != '\n' && j < a)
		{
			if (buf[j] == '\0')
				break ;
			j++;
		}
		if (buf[j] == '\n')
		{
			buf[j] = '\0';
			ft_memdel((void **)line);
			*line = ft_strjoin(tab[fd], buf);
			ft_bzero(tab[fd], sizeof(tab[fd]));
//			free(tmp);
			tab[fd] = ft_strdup((buf + (j + 1)));
			return (1);
		}
		j = 0;
		strcat(tab[fd], buf);
		memset(buf, '\0', BUFF_SIZE);
		free(buf);
		buf = ft_strnew(BUFF_SIZE + 1);
	}
	return (0);
}
