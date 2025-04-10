/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 07:44:44 by rmarcas-          #+#    #+#             */
/*   Updated: 2024/11/15 09:33:44 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*dst;
	const unsigned char		*str;
	size_t					i;

	i = 0;
	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (!str && !dst)
		return (NULL);
	while (i < n)
	{
		{
			dst[i] = str[i];
			i++;
		}
	}
	return (dst);
}
