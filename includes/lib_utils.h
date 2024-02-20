/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:20:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/19 14:05:26 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_UTILS_H
# define LIB_UTILS_H

# include <stddef.h>
# include <stdbool.h>

// FD
void	write_str_fd(char *str, int fd);
void	write_fd(char c, int fd);
// IS
bool	is_space(char c);
// CHECK
bool	str_good(char *str);
// PRINT
void	print_char(char c, int fd);
size_t	print_c(char c);
void	print_str(char *str);
void	print_error(char *str);
void	print_sent(char **str);
// LEN
size_t	str_len(char *str);
size_t	sent_len(char **sent);
// CMP
bool	str_cmp(char *str, char *str2);
bool	slib_cmp(char *str, char *str2);
bool	last_cmp(char *str, char *str2);
bool	in_lim(char *str, char *lim);
bool	str_ncmp(char *str, char *str2, size_t n);
// JOIN
char	*str_join(char *str1, char *str2);
char	*str1_join(char *str1, char *str2);
char	*str2_join(char *str1, char *str2);
char	*strall_join(char *str1, char *str2);
// DUP
char	*lib_strdup(char *str);
char	*lib_strup(char *str);
//		SENT
char	**copy_sent(char **sent);
char	**sentup(char *str);
char	**sentup_n(char **sent, char *str, size_t n);
// SPLIT
char	**lib_split(char *str, char *set);
// FREE
void	free_split(char **sent);
// SRCH
int		lib_srch(char *str, char to_find);

#endif