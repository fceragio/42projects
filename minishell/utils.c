/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:59:27 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 14:43:44 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	string_len(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		return (0);
	}
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	strings_are_equal(char *str1, char *str2)
{
	if (!str1 || !str2)
	{
		return (NO);
	}
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (NO);
		else
		{
			str1++;
			str2++;
		}
	}
	if (*str1 == *str2)
		return (YES);
	else
		return (NO);
}

char	*str_copy(char *str)
{
	char	*result;
	int		i;

	if (str == NULL)
	{
		return (NULL);
	}
	result = malloc(sizeof(char) * (string_len(str) + 1));
	if (result == NULL)
	{
		perror("str_copy ERROR: malloc\n");
		exit(SYS_ERR);
	}
	i = 0;
	while (i < string_len(str))
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*realloc_string(char *old, char *new_str)
{
	char	*result;

	free(old);
	result = str_copy(new_str);
	return (result);
}

char	*string_minus_beginning(char *original, int trim_start)
{
	char	*result;
	int		i;

	if (original == NULL)
	{
		return (NULL);
	}
	result = malloc(sizeof(char) * (string_len(original) - trim_start + 1));
	if (result == NULL)
	{
		perror("string_minus_beginning ERROR: malloc\n");
		exit(SYS_ERR);
	}
	i = 0;
	while (original[trim_start])
	{
		result[i++] = original[trim_start++];
	}
	result[i] = '\0';
	return (result);
}
