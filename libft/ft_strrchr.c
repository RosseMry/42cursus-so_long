/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 07:50:49 by rmarcas-          #+#    #+#             */
/*   Updated: 2024/11/15 09:18:48 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	cc;

	i = ft_strlen((char *)str);
	cc = (unsigned char)c;
	while (i >= 0)
	{
		if (str[i] == cc)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
