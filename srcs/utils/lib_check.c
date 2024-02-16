/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:41:13 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/29 16:03:48 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_utils.h"
#include <stdio.h>
#include <stdbool.h>

bool	str_good(char *str)
{
	size_t	i;
	int		good;

	i = 0;
	good = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (is_space(str[i]) == false)
			good++;
		i++;
	}
	if (good > 0)
		return (true);
	return (false);
}
