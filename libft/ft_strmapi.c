/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 21:55:43 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/28 11:30:32 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	ptr = ft_memalloc(ft_strlen((char *)s) + 1);
	ret = ptr;
	if (ret)
	{
		while (*s != '\0')
		{
			*ptr = f(i, *s);
			ptr++;
			s++;
			i++;
		}
		*ptr = '\0';
	}
	return (ret);
}
