/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:39:11 by ekose             #+#    #+#             */
/*   Updated: 2023/10/11 12:39:11 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[i])
		i++;
	if (dstsize < i)
		return (ft_strlen(src) + dstsize);
	while ((src[j]) && (i < dstsize - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (len);
}
