/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:11:51 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/28 10:53:01 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putchar(long c)
{
	if (c < 128)
		write(1, &c, 1);
	if (c > 127 && c <= 255)
		write(1, &c, 2);
	if (c > 255)
		write(1, &c, 3);
}
