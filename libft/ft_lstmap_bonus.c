/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:29:40 by rmarcas-          #+#    #+#             */
/*   Updated: 2024/11/18 17:31:45 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*str;
	t_list	*elem;
	void	*content;

	if (!lst)
		return (0);
	str = 0;
	while (lst)
	{
		content = f(lst -> content);
		if (!content && str)
			return (ft_lstclear(&str, del), NULL);
		elem = ft_lstnew (content);
		if (!elem)
		{
			del(content);
			ft_lstclear(&str, del);
			return (0);
		}
		ft_lstadd_back(&str, elem);
		lst = lst->next;
	}
	return (str);
}
