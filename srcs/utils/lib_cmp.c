/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:56:55 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/16 13:22:43 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"
#include <stdbool.h>

bool	last_cmp(char *str, char *str2)
{
	size_t	i;
	size_t	j;

	i = str_len(str);
	j = str_len(str2);
	if (i < j)
		return (false);
	while (j > 0 && i > 0)
	{
		if (str[i] != str2[j])
			return (false);
		i--;
		j--;
	}
	return (true);
}

bool	slib_cmp(char *str, char *str2)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	if (str_len(str) > str_len(str2))
		return (false);
	while (str[i] || str2[j])
	{
		if (str[i] != str2[j])
			return (false);
		if (str[i])
			i++;
		if (str[j])
			j++;
	}
	return (true);
}

bool	str_cmp(char *str, char *str2)
{
	size_t	i;

	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (false);
		i++;
	}
	return (true);
}

bool	str_ncmp(char *str, char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] && str2[i] && i < n)
	{
		if (str[i] != str2[i])
			return (false);
		i++;
	}
	return (true);
}

bool	in_lim(char *str, char *lim)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (str[i] || lim[j])
	{
		if (lim[j] == 0)
		{
			if (str[i] == '\n' || str[i] == 0)
				return (true);
		}
		if (str[i] != lim[j])
			return (false);
		i++;
		j++;
	}
	return (true);
}
