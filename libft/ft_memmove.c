/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 07:50:09 by rmarcas-          #+#    #+#             */
/*   Updated: 2024/11/15 09:29:34 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*dst;
	unsigned char	*str;

	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (!dst && !str)
		return (0);
	else if (str <= dst)
	{
		while (size > 0)
		{
			{
				(dst)[size - 1] = (str)[size - 1];
				size--;
			}
		}
	}
	else
		ft_memcpy (dst, str, size);
	return (dst);
}
