/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:21:19 by federico          #+#    #+#             */
/*   Updated: 2024/04/27 17:50:45 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*spare;
	int		size;

	spare = lst;
	if (spare == NULL)
		return (0);
	size = 0;
	while (spare->next)
	{
		spare = spare->next;
		size++;
	}
	if (spare->next == NULL)
		size++;
	return (size);
}
