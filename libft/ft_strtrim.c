/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:53:28 by rmarcas-          #+#    #+#             */
/*   Updated: 2024/11/13 07:53:30 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*dest;
	char const	*start;
	int			i;
	int			size;

	i = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	start = s1;
	while (*s1)
		s1++;
	while (s1 >= start && ft_strrchr(set, *s1))
		s1--;
	size = s1 - start + 1;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (start <= s1)
	{
		dest[i++] = *start;
		start++;
	}
	dest[i] = 0;
	return (dest);
}
