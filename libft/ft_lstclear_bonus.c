/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:53:45 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/11 16:49:53 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*content;

	if (!(lst) || !(*lst) || !(del))
		return ;
	while (*lst != 0)
	{
		content = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = content;
	}
}
