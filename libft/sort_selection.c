/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 23:09:10 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/28 11:49:54 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	*sort_selection(int *arr, size_t n)
{
	size_t	i;
	size_t	min_index;
	size_t	j;
	int		*ptr;

	i = 0;
	j = 0;
	min_index = 0;
	ptr = arr;
	while (i < (n - 1))
	{
		min_index = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
			j++;
		}
		j = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = j;
		i++;
	}
	return (ptr);
}
