/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:25:08 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/15 16:39:50 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *src, unsigned int start, size_t len);
size_t	ft_strlen(const	char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
char	**ft_split(const char *s, char c);
char	*ft_utoa(unsigned int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif