/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:17:28 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/01 18:14:31 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	stock;
	int	x;

	x = 0;
	stock = 0;
	sign = 1;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == 32)
		x++;
	if (nptr[x] == '-' || nptr[x] == '+')
	{
		if (nptr[x + 1] == '-' || nptr[x + 1] == '+')
			return (0);
		if (nptr[x] == '-')
			sign *= -1;
		x++;
	}
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		stock = (stock * 10) + (nptr[x] - 48);
		x++;
	}
	return (stock * sign);
}
