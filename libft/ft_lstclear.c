/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:26:06 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/10 14:42:50 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*todel;
	t_list	*next;

	if (lst && del)
	{
		todel = *lst;
		while (todel)
		{
			next = todel->next;
			ft_lstdelone(todel, del);
			todel = next;
		}
		*lst = NULL;
	}
}
