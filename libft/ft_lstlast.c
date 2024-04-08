/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:35:51 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/10 14:43:01 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*slow;
	t_list	*fast;

	if (lst)
	{
		slow = lst;
		fast = lst->next;
		while (fast && fast->next)
		{
			if (slow == fast)
				return (NULL);
			slow = slow->next;
			fast = fast->next->next;
		}
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	else
		return (NULL);
}
