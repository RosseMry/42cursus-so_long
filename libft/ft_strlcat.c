/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 07:50:26 by rmarcas-          #+#    #+#             */
/*   Updated: 2024/11/14 16:37:52 by athanaelgerar    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strdest(char *dest, size_t size)
{
	size_t	i;

	i = 0;
	while (dest[i] && i < size)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	size_t	i;

	i = 0;
	size_dest = ft_strdest((char *)dest, size);
	size_src = ft_strlen((char *)src);
	if (size <= size_dest)
		return (size + size_src);
	while (src[i] && (size_dest + i) < (size - 1))
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (size_dest + size_src);
}
