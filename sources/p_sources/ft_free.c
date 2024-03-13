#include "../minishell.h"

void	free_split(char **spl)
{
	int	x;

	x = 0;
	while (spl[x])
	{
		free(spl[x]);
		x++;
	}
	free(spl);
}

void	fake_free_split(char **spl)
{
	int	x;

	x = 0;
	while (spl[x])
	{
		free(spl[x]);
		x++;
	}
}

void	ft_free_struct(t_struct **stru)
{
	t_struct	*content;

	if (!stru || !*stru)
		return ;
	while (*stru != 0)
	{
		content = (*stru)->next;
		ft_structdelone(*stru);
		*stru = content;
	}
	free(stru);
}