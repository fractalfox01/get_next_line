/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:26:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/28 11:32:58 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*help(char *n, char *h, char *ptr, char *needle)
{
	size_t	counter;
	size_t	nlen;

	counter = 0;
	nlen = ft_strlen(n);
	while (*h != '\0')
	{
		if (counter < nlen && *n == *h)
		{
			while (*n++ == *h && *h != '\0')
			{
				counter++;
				if (counter == 1)
					ptr = h;
				if (counter == nlen)
					return (ptr);
				h++;
			}
			h = ptr + 1;
			n = (char *)needle;
		}
		counter = 0;
		h++;
	}
	return (NULL);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;
	char	*ptr;

	h = (char *)haystack;
	n = (char *)needle;
	ptr = h;
	if (!(*n))
		return (h);
	return (help(n, h, ptr, (char *)needle));
}
