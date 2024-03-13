# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 16:06:25 by pirulenc          #+#    #+#              #
#    Updated: 2023/11/11 15:43:41 by pirulenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strlcat.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_split.c \
		ft_itoa.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_print_check.c \
		ft_printf.c \
		ft_put_hexa.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_lstnew_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c
		
CFLAGS = -Wall \
		-Werror \
		-Wextra
		
CC = cc

AR = ar -rcs

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(OBJECTS)
		$(AR) $(NAME) $(OBJECTS)

$(NAME): $(OBJECTS)
		$(AR) $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
