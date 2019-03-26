/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:58:50 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/25 20:28:39 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	int delta;

	delta = 1;
	while (n)
	{
		if (n >= 8)
		{
			*(double *)s = 0;
			delta = 8;
		}
		else if (n >= 1)
		{
			*(char *)s = 0;
			delta = 1;
		}
		n = n - delta;
		s = ((char *)s) + delta;
	}
}
