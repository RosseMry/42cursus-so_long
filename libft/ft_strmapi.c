/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:49:31 by rmarcas-          #+#    #+#             */
/*   Updated: 2024/11/15 09:22:21 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (0);
	str = ft_strdup((char *)s);
	if (!str)
		return (0);
	while (str[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
