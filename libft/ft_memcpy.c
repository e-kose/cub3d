/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:47:58 by ekose             #+#    #+#             */
/*   Updated: 2023/10/23 11:43:08 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sourc;

	i = 0;
	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	if (!dest && !sourc)
		return (0);
	while (i < n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dest);
}
