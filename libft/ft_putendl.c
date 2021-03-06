/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:44:42 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/22 15:40:57 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putendl(char const *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (*str != '\0')
		{
			ft_putchar(*str);
			str++;
			i++;
		}
		ft_putchar('\n');
	}
}
