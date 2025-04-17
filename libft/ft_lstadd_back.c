/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:14:32 by federico          #+#    #+#             */
/*   Updated: 2024/04/27 17:43:57 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*spare;

	if (*lst == NULL)
		*lst = new;
	else
	{
		spare = ft_lstlast(*(lst));
		spare->next = new;
	}
}
