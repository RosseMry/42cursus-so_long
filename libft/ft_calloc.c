/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:16:14 by rmarcas-          #+#    #+#             */
/*   Updated: 2024/11/15 09:32:12 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*str;
	size_t			total;
	size_t			totalsize;

	totalsize = (size_t)(-1);
	if (size != 0 && n > totalsize / size)
		return (0);
	total = n * size;
	str = malloc(total);
	if (!str)
		return (0);
	ft_memset(str, '\0', total);
	return (str);
}	
