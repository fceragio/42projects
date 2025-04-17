/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:17:02 by federico          #+#    #+#             */
/*   Updated: 2024/05/01 01:52:51 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*spare;

	if (lst)
	{
		while (*lst)
		{
			spare = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = spare;
		}
	}
}
