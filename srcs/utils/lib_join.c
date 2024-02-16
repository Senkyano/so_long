/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:29:02 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/30 17:12:34 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"
#include <stdlib.h>

char	*str_join(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	new_str = malloc((str_len(str1) + str_len(str2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		new_str[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		new_str[i + j] = str2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

char	*str1_join(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!str1)
	{
		str1 = malloc(1 * sizeof(char));
		if (!str1)
			return (NULL);
		str1[0] = '\0';
	}
	new_str = malloc((str_len(str1) + str_len(str2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (str1[++i])
		new_str[i] = str1[i];
	while (str2[++j])
		new_str[i++] = str2[j];
	new_str[i] = '\0';
	free(str1);
	return (new_str);
}

char	*str2_join(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	new_str = malloc((str_len(str1) + str_len(str2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (str1[++i])
		new_str[i] = str1[i];
	while (str2[++j])
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	free(str2);
	return (new_str);
}

char	*strall_join(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	new_str = malloc((str_len(str1) + str_len(str2) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (str1[++i])
		new_str[i] = str1[i];
	while (str2[++j])
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	free(str2);
	free(str1);
	return (new_str);
}
