/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:49:13 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/28 11:28:32 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_realloc(void *tab, size_t size)
{
	void	*ptr;

	ptr = ft_memalloc(size);
	if (!tab || ptr)
		return (NULL);
	ptr = ft_memcpy(ptr, tab, sizeof(tab));
	free(tab);
	return (ptr);
}
