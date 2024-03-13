/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:11:02 by pirulenc          #+#    #+#             */
/*   Updated: 2023/12/07 13:05:52 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_int(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_int(const char *str)
{
	int	x;

	x = 0;
	if (!(str))
		return (ft_putstr_int("(null)"));
	while (str[x] != '\0')
	{
		ft_putchar_int(str[x]);
		x++;
	}
	return (x);
}

int	ft_putnbr_int(int nbr)
{
	int	stock;

	stock = 0;
	if (nbr == -2147483648)
	{
		stock = write(1, "-2147483648", 11);
		return (stock);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		stock = ft_putnbr_int((nbr * -1)) + 1;
	}
	else if (nbr >= 10)
	{
		stock += ft_putnbr_int((nbr / 10));
		stock += ft_putnbr_int((nbr % 10));
	}
	else
		stock += ft_putchar_int((nbr + '0'));
	return (stock);
}

int	ft_putnbr_unsint(unsigned int nbr)
{
	int	stock;

	stock = 0;
	if (nbr >= 10)
	{
		stock += ft_putnbr_int((nbr / 10));
		stock += ft_putnbr_int((nbr % 10));
	}
	else
		stock += ft_putchar_int((nbr + '0'));
	return (stock);
}
