/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:33:15 by federico          #+#    #+#             */
/*   Updated: 2024/05/02 23:51:02 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeup(char *strs)
{
	int	i;

	i = 0;
	while (strs[i] != '\0')
	{
		free(strs);
		i++;
	}
	free(strs);
}

static int	ft_wordcount(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

static void	ft_strcpy(char *word, char *s, char c, int j)
{
	int	i;

	i = 0;
	while (s[j] != '\0' && s[j] == c)
		j++;
	while (s[j + i] != c && s[j + i] != '\0')
	{
		word[i] = s[j + i];
		i++;
	}
	word[i] = '\0';
}

static char	*ft_stralloc(char *s, char c, int *k)
{
	char	*word;
	int		j;

	j = *k;
	word = NULL;
	while (s[*k] != '\0')
	{
		if (s[*k] != c)
		{
			while (s[*k] != '\0' && s[*k] != c)
				*k += 1;
			word = (char *)malloc(sizeof(char) * (*k + 1));
			if (word == NULL)
				return (NULL);
			break ;
		}
		*k += 1;
	}
	ft_strcpy(word, s, c, j);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (s == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount((char *)s, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = ft_stralloc(((char *)s), c, &pos);
		if (strs[i] == NULL)
		{
			ft_freeup(strs[i]);
		}
		i++;
	}
	return (strs);
}

// #include <stdio.h>

// static void	ssPrint(char	**str, size_t size);

// int main()
// {
// 	char	*str = "This  is the   string     before the split.";
// 	char	sep = ' ';
// 	char	**splitted;
// 	int		i;

// 	splitted = ft_split(str, sep);
// 	printf("Unsplitted:\n\n%s\n\n\nSplitted:\n\n", str);
// 	ssPrint(splitted, ft_wordcount(str, sep));
// 	for (i = 0; splitted[i] != NULL; i++)
// 		free(splitted[i]);
// 	free(splitted[i]);
// 	free(splitted);

// 	return 0;
// }

// static	void	ssPrint(char **str, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}
// 	printf("\n");
// }