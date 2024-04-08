/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:20:39 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/10 14:42:40 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new)
	{
		if (lst && *lst)
		{
			if (*lst && lst && new)
			{
				last = ft_lstlast(*lst);
				last->next = new;
			}
		}
		else
			*lst = new;
	}
}
