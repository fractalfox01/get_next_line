/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:17:06 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/28 11:49:37 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	*sort_bubble(int *arr, size_t len)
{
	size_t	i;
	size_t	j;
	int		x;

	i = 0;
	j = 1;
	x = 0;
	while (i < len && (i + 1) != len)
	{
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				x = arr[i];
				arr[i] = arr[j];
				arr[j] = x;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (arr);
}
