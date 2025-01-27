/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 07:50:31 by rmarcas-          #+#    #+#             */
/*   Updated: 2024/11/15 09:15:16 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;
	char	*str;

	str = (char *)src;
	i = 0;
	lensrc = ft_strlen (str);
	if (size != 0)
	{
		while (str[i] && (i < (size - 1)))
		{
			dst[i] = str[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (lensrc);
}
