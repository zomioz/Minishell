/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:30:36 by pirulenc          #+#    #+#             */
/*   Updated: 2023/12/07 13:05:31 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char c, va_list	content)
{
	int		stock;
	char	*tabx1;
	char	*tabx2;

	tabx1 = "0123456789abcdef";
	tabx2 = "0123456789ABCDEF";
	stock = 0;
	if (c == 'c')
		stock = ft_putchar_int(va_arg(content, int));
	else if (c == 's')
		stock = ft_putstr_int(va_arg(content, char *));
	else if (c == 'd' || c == 'i')
		stock = ft_putnbr_int(va_arg(content, int));
	else if (c == 'u')
		stock = ft_putnbr_unsint(va_arg(content, unsigned int));
	else if (c == '%')
		stock = ft_putchar_int('%');
	else if (c == 'x')
		stock = ft_putnbr_base_int(va_arg(content, unsigned int), tabx1);
	else if (c == 'X')
		stock = ft_putnbr_base_int(va_arg(content, unsigned int), tabx2);
	else if (c == 'p')
		stock = ft_putp_int(va_arg(content, unsigned long long *));
	return (stock);
}

int	ft_printf(const char *str, ...)
{
	int		x;
	int		stock;
	va_list	content;

	if (!(str))
		return (-1);
	va_start(content, str);
	x = 0;
	stock = 0;
	while (str[x] != '\0')
	{
		if (str[x] == '%')
		{
			stock += ft_check(str[x + 1], content);
			x++;
		}
		else
		{
			ft_putchar_int(str[x]);
			stock++;
		}
		x++;
	}
	va_end(content);
	return (stock);
}
