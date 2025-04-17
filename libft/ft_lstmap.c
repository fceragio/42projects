/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:08:18 by federico          #+#    #+#             */
/*   Updated: 2024/05/01 23:30:06 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;

	if (!f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		tail = ft_lstnew((*f)(lst->content));
		if (!tail)
		{
			while (head)
			{
				tail = head->next;
				(*del)(head->content);
				free(head);
				head = tail;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&head, tail);
		lst = lst->next;
	}
	return (head);
}
