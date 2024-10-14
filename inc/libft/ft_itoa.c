/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:43:34 by ekose             #+#    #+#             */
/*   Updated: 2023/10/20 19:04:46 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nmb_size(long c)
{
	size_t	i;

	i = 0;
	if (c <= 0)
	{
		if (c == 0)
			return (1);
		c *= -1;
		i++;
	}
	while (c >= 1)
	{
		c /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	size;
	long	num;

	num = n;
	size = ft_nmb_size(n);
	p = (char *)malloc(sizeof(char) * size + 1);
	if (p == NULL)
		return (0);
	if (num < 0)
	{
		num *= -1;
		p[0] = '-';
	}
	if (num == 0)
		p[0] = '0';
	p[size] = '\0';
	while (num != 0)
	{
		p[size - 1] = (num % 10) + '0';
		num = num / 10;
		size--;
	}
	return (p);
}
