/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:59:15 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/11 16:49:39 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!(new))
		return ;
	current = *lst;
	if (*lst == 0)
		return (ft_lstadd_front(lst, new));
	current = ft_lstlast(*lst);
	current->next = new;
}
