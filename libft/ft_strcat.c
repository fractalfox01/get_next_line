/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:12:22 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/22 15:42:14 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** ft_strcat copies all the characters from src to the end of dest.
**
** NOTE:
**  The 'dest' character array must be large enough to hold the resulting
**  combination of both strings.
**  "buffer overruns are a favorite avenue for attacking secure programs." - Linux man pages
*/

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	if (!(*src))
		return (ptr);
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (ptr);
}
