/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:52:29 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/25 17:31:18 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	int			fd;
	int			fd1;
	char		*buf;
	char		*buf1;
	char		a;
	int			i;

//	a = 1;
	i = 0;
	if (ac == 1)
	{
		char *line = "a simple test string\nb simple test string\nc simple test string\nd simple test string\n";
		printf("Enter a file name.\n");
		if (get_next_line(-99, &line) == -1)
			printf("minus 1\n");
		else
			printf("returned: %d\n", get_next_line(-99, &line));
	}
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((a = get_next_line(fd, &buf)) > 0)
		{
			i++;
			printf("\033[0;35m%s\n", buf);
		}
		close(fd);
	}
	else if (ac == 3)
	{
		if (ft_strcmp(av[1], "debug") == 0)
		{
			fd = open(av[2], O_RDONLY);
			while ((a = get_next_line(fd, &buf)) > 0)
			{
				i++;
				printf("\033[0;35m%s\n", buf);
			}
			printf("\n\033[0;32m\u0305 \u0305 \u0305 \u0305 \u0305 \u0305 \u0503e\u0499\u0299\u0216\u050d\u050d\u0671\u05deg  \u0305 \u0305 \u0305 \u0305 \u0305 \u0305\n\n");
			printf("Buffer Length:\t%d\n", BUFF_SIZE);
			printf("buf Length:\t%zu\n", ft_strlen(buf));
			printf("Line Count:\t%d\n", i);
			close(fd);
		}
		else
		{
			fd = open(av[1], O_RDONLY);
			fd1 = open(av[2], O_RDONLY);
			while ((a = get_next_line(fd, &buf)) > 0)
			{
				printf("\033[0;34m%s\n", buf);
				if ((a = get_next_line(fd1, &buf1)) > 0)
					printf("\033[0;32m%s\n", buf1);
			}
			close(fd);
			close(fd1);
		}
	}
	return (0);
}
