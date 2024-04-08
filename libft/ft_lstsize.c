/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:39:35 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/10 14:43:17 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lstnb;
	t_list	*slow;
	t_list	*fast;

	lstnb = 0;
	slow = lst;
	fast = lst;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (0);
	}
	while (lst)
	{
		lstnb++;
		lst = lst->next;
	}
	return (lstnb);
}
