#include "../minishell.h"

int	ft_check_tokens(char *content)
{
	if (content && content[0] == '<' && !content[1])
		return (2);
	else if (content && content[0] == '<' && content[1] == '<')
		return (5);
	else if (content && content[0] == '>' && content[1] == '>')
		return (6);
	else if (content && content[0] == '>')
		return (3);
	else if (content && content[0] == '|')
		return (4);
	else
		return (0);
}

void	ft_go_tokens(t_struct **stru)
{
	t_struct *head;

	head = (*stru);
	while ((*stru))
	{
		if (ft_is_sep((*stru)->content))
			(*stru)->tkn = ft_check_tokens((*stru)->content);
		else if ((*stru)->prev && ((*stru)->prev->tkn == 2
			|| (*stru)->prev->tkn == 3
			|| (*stru)->prev->tkn == 5
			|| (*stru)->prev->tkn == 6))
			(*stru)->tkn = 7;
		else
			(*stru)->tkn = 1;
		(*stru) = (*stru)->next;
	}
	(*stru) = head;
}