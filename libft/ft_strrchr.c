/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:47:00 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/04 16:04:28 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int				x;
	int				stock;
	unsigned char	c2;

	x = 0;
	stock = -1;
	c2 = c;
	while (s[x] != '\0')
	{
		if (s[x] == c2)
			stock = x;
		x++;
	}
	if (s[x] == '\0' && c2 == '\0')
		return ((char *)s + x);
	if (stock != -1)
		return ((char *)s + stock);
	else
		return (0);
}
