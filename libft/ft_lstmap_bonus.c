/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:32:38 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/11 16:50:27 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*end_lst;

	if (!(lst) || !(f) || !(del))
		return (0);
	end_lst = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		current = ft_lstnew(f(lst->content));
		ft_lstadd_back(&end_lst, current);
		lst = lst->next;
	}
	return (end_lst);
}
