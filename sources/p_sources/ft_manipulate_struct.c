/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulate_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:31:07 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/25 20:31:08 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_struct	*ft_structlast(t_struct *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_structadd_front(t_struct **lst, t_struct *new)
{
	if (!(lst) || !(new))
		return ;
	(*lst)->prev = new;
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}

void    ft_structadd_back(t_struct **lst, t_struct *new)
{
    t_struct    *last;

    if (!new || !lst)
        return ;
    if (*lst == NULL)
    {
        *lst = new;
        new->next = NULL;
        new->prev = NULL;
    }
    else
    {
        last = ft_structlast(*lst);
        new->prev = last;
        last->next = new;
    }
}

t_struct	*ft_structnew(char *content, char **envp)
{
	t_struct			*list;

	list = malloc(sizeof(t_struct));
	if (!list)
		return (0);
	list->content = ft_strdup(content);
	list->next = 0;
	list->prev = 0;
	list->envp = ft_dupenvp(envp);
	list->tkn = 0;
	return (list);
}

void	ft_structdelone(t_struct *stru)
{
	int	x;

	x = 0;
	if (!stru)
		return ;
	free(stru->content);
	while (stru->envp[x])
	{
		free(stru->envp[x]);
		x++;
	}
	free(stru->envp);
	stru->envp = 0;
	stru->content = 0;
	free(stru);
}