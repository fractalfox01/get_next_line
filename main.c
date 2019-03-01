#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	int			fd;
	static char	buf[32];
//	const char	*adr;
	char		**addr;
	int			i;
	char		a;

	a = 'a';
	i = 0;
	if (ac == 1)
	{
		printf("Enter a file name.\n");
	}
	else if (ac == 2)
	{
//		buf = (char *)ft_memalloc(BUF_SIZE);
//		adr = av[1];
		ft_memset(buf, 'a', BUF_SIZE - 1);
		fd = open(av[1], O_RDONLY);
//		printf("fd: %d\n", fd);
//		printf("Addr: %s\n", &*buf);
		addr = (char **)malloc(BUF_SIZE);
		*addr = buf;
//		printf("%zu\n", sizeof(*addr));
//		printf("%zu\n", sizeof(&*buf));
//		printf("%zu\n", sizeof(buf));
		ft_memset(*addr, '\0', BUF_SIZE);
//		while (i < (BUF_SIZE - 1))
//		{
//			ft_memset(*addr + i++, a++, 1);
//			if (a == ('z' + 1))
//				a = 'a';
//		}
//		if (*addr)
//		{
			while (get_next_line(fd, addr))
			{
				printf("%s\n", buf);
			}
				close(fd);
//		}
	}
	return (0);
}
