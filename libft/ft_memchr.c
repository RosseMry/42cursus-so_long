/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 07:44:28 by rmarcas-          #+#    #+#             */
/*   Updated: 2024/11/15 09:19:01 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	char	*str;

	str = (void *)s;
	while (size--)
	{
		if (*str == ((char)c))
			return (str);
		str++;
	}
	return (0);
}
