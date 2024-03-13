# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 09:36:14 by pirulenc          #+#    #+#              #
#    Updated: 2024/03/12 22:19:28 by pirulenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCES = sources/p_sources/main.c \
		sources/p_sources/ft_manipulate_struct.c \
		sources/p_sources/ft_treat_readline.c \
		sources/p_sources/ft_treat_readline_utils.c \
		sources/p_sources/ft_free.c \
		sources/p_sources/ft_print_struct.c \
		sources/p_sources/ft_create_tokens.c \
		sources/p_sources/ft_checker.c \
		sources/p_sources/ft_treat_quote.c \
		sources/p_sources/ft_split_sep.c \
		sources/q_sources/cmd.c \
		sources/q_sources/data_treat.c \
		sources/q_sources/heredoc.c \
		sources/q_sources/pipe.c \
		sources/q_sources/simple_exec.c \
		sources/q_sources/utils.c \

CFLAGS = -Wall \
			-Werror \
			-Wextra \
			-g \

CC = cc

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@${MAKE} -j -C ./libft -s
	@echo LIBFT COMPILED : ✓
	@$(CC) $(CFLAGS) $(OBJECTS) ./libft/libft.a -o $(NAME) -lreadline
	@echo MINISHELL COMPILED : ✓

clean:
	@${MAKE} -C ./libft clean -s
	@echo LIBFT CLEAN : ✓
	@rm  -f $(OBJECTS)
	@echo MINISHELL CLEAN : ✓

fclean: clean
	@${MAKE} -C ./libft fclean -s
	@echo LIBFT FCLEAN : ✓
	@rm -f $(NAME)
	@echo MINISHELL FCLEAN : ✓

re: fclean all
