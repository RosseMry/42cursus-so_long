/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 07:43:23 by rmarcas-          #+#    #+#             */
/*   Updated: 2024/11/16 07:43:23 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*i;

	if (!*lst)
		return ;
	while (*lst)
	{
		i = (*lst)-> next;
		ft_lstdelone (*lst, del);
		*lst = i;
	}
	*lst = 0;
}
