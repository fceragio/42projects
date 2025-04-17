/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:19:08 by federico          #+#    #+#             */
/*   Updated: 2024/04/27 17:42:35 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*spare;

	spare = lst;
	if (spare == NULL)
		return (NULL);
	while (spare->next)
		spare = spare->next;
	return (spare);
}
