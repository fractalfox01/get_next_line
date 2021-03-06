/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:13:06 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/28 11:29:28 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*nstr;
	int		len;
	int		i;

	len = ft_strlen((char *)s);
	nstr = (char *)malloc(sizeof(char) * (len + 1));
	if (nstr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		nstr[i] = s[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
