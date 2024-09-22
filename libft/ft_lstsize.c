/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:22:48 by ekose             #+#    #+#             */
/*   Updated: 2023/10/20 14:45:33 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	size_t	i;

	tmp = lst;
	i = 0;
	if (!lst)
		return (0);
	while (tmp != NULL)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}
