
#ifndef MINISHELL_H
# define MINISHELL_H


# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_struct
{
	char **envp;
	int	tkn;
	char *content;
	struct s_struct *next;
	struct s_struct *prev;
}t_struct;

//FT_MANIPULATE_STRUCT
t_struct	*ft_structlast(t_struct *lst);
void		ft_structadd_front(t_struct **lst, t_struct *new);
void		ft_structadd_back(t_struct **lst, t_struct *new);
t_struct	*ft_structnew(char *content, char **envp);
void		ft_structdelone(t_struct *stru);

//FT_TREAT_READLINE
void		ft_treat_read(char *str, char **envp);

//FT_TREAT_READLINE_UTILS
int			ft_is_sep(char *spl);
char		*ft_strcat(char *s1, char *s2);
void		ft_recreate_split(char **spl, int cut);
void		ft_file_struct(char **spl, char **envp);
char		**ft_dupenvp(char **envp);

//FT_SPLIT_SEP
char	**ft_split_sep(char *str);

//FT_TREAT_QUOTE
void	ft_check_quote(char **spl);

//FT_CHECKER
char	*ft_checker(char *str);
int		ft_count_quote(char *str, char c);

//FT_FREE
void		free_split(char **spl);
void		ft_free_struct(t_struct **stru);
void		fake_free_split(char **spl);

//FT_CREATE_TOKEN
void		ft_go_tokens(t_struct **stru);

//FT_PRINT_STRUCT
void		ft_printf_stack(t_struct *stru);

//DATA_TREAT
void		trim_tab(char **cmd);
int			ft_quote(char *content);
void		exec_cmd(char *argv, char **envp);
int			check_pipe(t_struct **data);
void		treat_data(t_struct **prompt);

//SIMPLE_EXEC
int			check_and_open_infile(t_struct **data);
int			check_and_open_outfile(t_struct **data);
int			check_and_start_heredoc(t_struct **data);
void		exec_simple_command(t_struct **data);

//CMD
void		check_cmd(char *path, char **cmd, char *content);
char		**find_cmd_with_path(char *content);
char		**find_envpath(char **envp);
int			ft_access(char *path, char *cmds);
char		*find_path(char **cmd, char **envp);

//PIPE
void		restore_stdfd(int *savefd);
void		find_next_block(t_struct **data);
void		pipe_use(int *pipefd, int mode);
void		exec_pipe(t_struct **data, int npipe, int *pipefd);

//UTILS
void		free_all(char *str, char **tab);
int			mode_open_outfile(char *file, int mode);
void		free_multi_str(char *s1, char *s2);
int			size_struct(t_struct **stru);

//HEREDOC
void		here_in(char *limiter, int *pipefd);
void		do_heredoc(char *content);

#endif
