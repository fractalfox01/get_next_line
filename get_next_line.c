/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:05:09 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/01 14:30:49 by tvandivi         ###   ########.fr       */
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
	int			len;
	static int	count;
	char		*ptr;
	int			i;
	int			x;
	int			y;

	ret = 0;
	if (!fd)
		return (0);
	if (*line)
	{
		if (count)
			ptr = *line + (BUF_SIZE * count);
		else
			ptr = *line;
		y = BUF_SIZE * (count + 1);
		if (count > 0)
		{
			len = read(fd, ptr, y + 1);
		}
		else
			len = read(fd, ptr, BUF_SIZE);
		i = len;
		x = BUF_SIZE * (count + 1);
		if (len > 0)
		{
			if (count > 0)
			{
				while (x < 0)
				{
					if (ptr[x] == '\n')
						y++;
					if (y == count)
						break ;
					x--;
				}
			}
			while (len >= 0)
			{
				if (ptr[x - len] == 10)
				{
					count++;
					break ;
				}
				//ft_putchar(ptr[x - len]);
				len--;
			}
			if (len == 0 && ft_isprint(ptr[x - 1]))
				return (0);
			if (count > 0)
				ft_realloc(ptr, (BUF_SIZE * count));
			return (1);
		}
	}
	return (0);
}
