#include "../minishell.h"

void	ft_printf_stack(t_struct *stru)
{
	int	x;

	x = 0;
	//while (stru && stru->envp[x])
	//{
	//	ft_printf("%s\n", stru->envp[x]);
	//	x++;
	//}
	while (1)
	{
		if (stru->next == NULL)
		{
			ft_printf("%s  -> MY TKN IS: %d\n", stru->content, stru->tkn);
			return ;
		}
		ft_printf("%s  -> MY TKN IS: %d\n", stru->content, stru->tkn);
		stru = stru->next;
	}
}