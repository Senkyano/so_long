/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:22:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/26 18:54:55 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"
#include <stddef.h>

size_t	sent_len(char **sent)
{
	size_t	i;

	i = 0;
	if (!sent)
		return (0);
	while (sent[i])
		i++;
	return (i);
}

size_t	str_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
