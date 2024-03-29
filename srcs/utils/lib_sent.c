/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_sent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:33:02 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/20 13:39:17 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"
#include <stdlib.h>
#include <stdio.h>

char	**sentup_n(char **sent, char *str, size_t n)
{
	char	**new_sent;
	size_t	i;

	if (n == 1 && (!sent || sent == NULL))
		return (sentup(str));
	i = 0;
	new_sent = malloc(sizeof(char *) * (n + 1));
	if (!new_sent)
		return (NULL);
	new_sent[n] = NULL;
	while (sent[i] != NULL)
	{
		new_sent[i] = lib_strup(sent[i]);
		if (new_sent[i] == NULL)
			return (free_split(new_sent), NULL);
		i++;
	}
	new_sent[i] = lib_strup(str);
	if (new_sent[i] == NULL)
		return (free_split(new_sent), NULL);
	free_split(sent);
	return (new_sent);
}

char	**copy_sent(char **sent)
{
	char	**cp_sent;
	size_t	i;
	size_t	j;

	i = sent_len(sent);
	j = 0;
	cp_sent = malloc((i + 1) * sizeof(char *));
	if (!cp_sent)
		return (NULL);
	while (sent[j])
	{
		cp_sent[j] = lib_strup(sent[j]);
		if (cp_sent[j] == NULL)
			return (free_split(cp_sent), NULL);
		j++;
	}
	cp_sent[j] = NULL;
	return (cp_sent);
}

char	**sentup(char *str)
{
	char	**new_sent;

	if (!str)
		return (NULL);
	new_sent = malloc(sizeof(char *) * 2);
	if (!new_sent)
		return (NULL);
	new_sent[0] = lib_strup(str);
	if (!new_sent[0])
		return (free(new_sent), NULL);
	new_sent[1] = NULL;
	return (new_sent);
}
