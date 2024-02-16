/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:37:52 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/01 17:27:27 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"
#include <stdlib.h>
#include <stdio.h>

static int	is_charset(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	nbr_words(char *str, char *set)
{
	size_t	word;

	word = 0;
	while (*str != '\0')
	{
		while (is_charset(*str, set) && *str != '\0')
			str++;
		if (!is_charset(*str, set) && *str != '\0')
			word++;
		while (!is_charset(*str, set) && *str != '\0')
			str++;
	}
	return (word);
}

static size_t	len_word(char *str, char *set)
{
	size_t	i;

	i = 0;
	while (!is_charset(str[i], set) && str[i])
		i++;
	return (i);
}

static char	*malloc_word(char *str, char *set)
{
	char	*word;
	size_t	i;

	i = 0;
	if (str[0] == 0)
	{
		word = malloc(sizeof(char));
		if (!str)
			return (NULL);
		word[0] = '\0';
		return (word);
	}
	word = malloc(sizeof(char) * (len_word(str, set) + 1));
	if (!word)
		return (NULL);
	while (!is_charset(*str, set) && *str)
	{
		word[i++] = *str;
		str++;
	}
	word[i] = '\0';
	return (word);
}

char	**lib_split(char *str, char *set)
{
	char	**sent;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	printf("%zu\n", nbr_words(str, set));
	sent = malloc(sizeof(char *) * (nbr_words(str, set) + 1));
	if (!sent)
		return (NULL);
	while (*str)
	{
		while (is_charset(*str, set) && *str)
			str++;
		if (!is_charset(*str, set) && *str)
		{
			sent[i] = malloc_word(str, set);
			if (!sent[i++])
				return (free_split(sent), NULL);
		}
		while (!is_charset(*str, set) && *str)
			str++;
	}
	sent[i] = NULL;
	return (sent);
}
