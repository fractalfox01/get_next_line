/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:05:09 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/03 21:00:31 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static char *tab[4096];
	char		*new_line;
	int			start;
	int			end;
	int	i;
	static int	word_count;
	int			flag;

	start = 0;
	end = 0;
	ret = 0;
	flag = 1;
	i = 0;
	if (!fd)
		return (0);
	if (*line)
	{
		tab[fd] = ft_strnew(BUFF_SIZE + 1);
		if ((ret = read(fd, tab[fd], BUFF_SIZE)) > 0)
		{
			while (i < (BUFF_SIZE * (word_count + 1)))
			{
				if (tab[fd][i] == '\n')
				{
					end = i;
					word_count++;
					tab[fd][i] = '\0';
					ft_memcpy(*line, tab[fd], (end));
					break ;
				}
			//	printf("tab[%d][%d] = %c\n", fd, i, tab[fd][i]);
				i++;
			}	
			if (ret == BUFF_SIZE || tab[fd][end] == '\n')
			{
				return (1);
			}
			return (0);
		}
	}
	return (0);
}
