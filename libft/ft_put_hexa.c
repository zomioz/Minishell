/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:03:06 by pirulenc          #+#    #+#             */
/*   Updated: 2023/12/27 11:02:50 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_int(unsigned int nbr, const char *tab)
{
	int	stock;

	stock = 0;
	if (nbr >= 16)
	{
		stock += ft_putnbr_base_int((nbr / 16), tab);
		stock += ft_putnbr_base_int((nbr % 16), tab);
	}
	else
		stock += ft_putchar_int(tab[nbr]);
	return (stock);
}

int	ft_putnbr_llu_int(long long unsigned int nbr, const char *tab)
{
	int	stock;

	stock = 0;
	if (nbr >= 16)
	{
		stock += ft_putnbr_llu_int((nbr / 16), tab);
		stock += ft_putnbr_llu_int((nbr % 16), tab);
	}
	else
		stock += ft_putchar_int(tab[nbr]);
	return (stock);
}

int	ft_putp_int(unsigned long long *str)
{
	int	stock;

	stock = 0;
	if (!str)
	{
		stock += ft_putstr_int("(nil)");
		return (stock);
	}
	stock += ft_putchar_int('0');
	stock += ft_putchar_int('x');
	stock += ft_putnbr_llu_int((long long unsigned int)str, "0123456789abcdef");
	return (stock);
}
