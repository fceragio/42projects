/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:18:32 by federico          #+#    #+#             */
/*   Updated: 2024/05/01 23:39:00 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*spare;

	spare = lst;
	while (spare)
	{
		f(spare->content);
		spare = spare->next;
	}
}

// #include <stdio.h>

// static void	print_adress(void *node_content)
// {
// 	printf("%p\n", node_content);
// }

// static void	delete_function(void *node_content)
// {
// 	if (node_content)
// 		node_content = '\0';
// }

// static void *mem_plus_1(void *ptr)
// {
// 	char	*new;

// 	new = (char *)ptr + 1;
// 	return (new);
// }

// int main()
// {
// 	int		size;
// 	int		x = 5;
// 	char 	*str = "String for the list.";
// 	char	*str2 = "This is the string of a new node.";

// 	t_list	*lInt;
// 	t_list	*lStr;
// 	t_list	*lastNode;
// 	t_list	*newNode;
// 	t_list	*newList;

// 	lInt = ft_lstnew(&x);
// 	lStr = ft_lstnew(str);

// 	printf("lInt contains \"%d\"\n", *(int *)lInt->content);
// 	printf("lStr contains \"%s\"\n", (char *)lStr->content);
// 	printf("\n");

// 	size = ft_lstsize(lInt);
// 	printf("Now the size of lInt is\nsize = %d\n", size);
// 	printf("\n");

// 	ft_lstadd_front(&lStr, lInt);
// 	size = ft_lstsize(lInt);
// 	printf("If we add lInt at the front of lStr\nsize = %d\n", size);
// 	printf("\n");

// 	lastNode = ft_lstlast(lInt);
// 	printf("Infact now the content of the last node of lInt is\n");
// 	printf("%s\n", (char *)lastNode->content);
// 	printf("\n");

// 	newNode = ft_lstnew(str2);
// 	printf("If now we add at the back of the queued lists newNode\n");
// 	ft_lstadd_back(&lInt, newNode);
// 	size = ft_lstsize(lInt);
// 	printf("the new size will be %d, and the last node will contain\n", size);
// 	lastNode = ft_lstlast(lInt);
// 	printf("%s\n\n", (char *)lastNode->content);

// 	printf("If now we iterate the print_adress funtion, we get:\n");
// 	ft_lstiter(lInt, print_adress);
// 	printf("\n");

// 	printf("Lets try to use lstmap on this list\n");
// 	newList = ft_lstmap(lInt, mem_plus_1, delete_function);
// 	size = ft_lstsize(newList);
// 	printf("The new list size is %d\n", size);
// 	printf("The new list dresses are:\n");
// 	ft_lstiter(newList, print_adress);

// 	printf("In the end, free all the nodes of the list, to avoid leeks.\n");
// 	ft_lstclear(&newList, delete_function);
// 	ft_lstclear(&lInt, delete_function);

// 	return 0;
// }