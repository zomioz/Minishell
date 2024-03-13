/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:54:14 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/09 11:09:09 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	stock;

	stock = 0;
	if (n == 0)
		return (1);
	while ((n / 10 != 0) || (n % 10 != 0))
	{
		n = n / 10;
		stock++;
	}
	return (stock);
}

static void	ft_fill_itoa(char *dest, int n, int sign, int nbr_m)
{
	ft_bzero(dest, nbr_m + 1);
	if (sign != 0)
	{
		dest[0] = '-';
		if (sign == 2)
			dest[1] = '2';
	}
	while (nbr_m > sign)
	{
		dest[nbr_m - 1] = (n % 10) + 48;
		n = n / 10;
		nbr_m--;
	}
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		nbr_m;
	int		sign;

	sign = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			sign = 2;
			n = -147483648;
		}
		else
			sign = 1;
		n = n * -1;
	}
	nbr_m = ft_intlen(n);
	if (sign != 0)
		nbr_m = nbr_m + sign;
	dest = malloc((nbr_m + 1) * sizeof(char));
	if (!(dest))
		return (0);
	ft_fill_itoa(dest, n, sign, nbr_m);
	return (dest);
}
