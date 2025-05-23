/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:32:28 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/23 09:33:39 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

int		ft_strlen(const char *s);

void	*ft_memset(void *b, int c, int len);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memmove(void *dst, const void *src, int len);

int		ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_strlcat(char *dst, const char *src, int dstsize);

int		ft_toupper(int c);
int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, int n);

int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);

char	*ft_strnstr(const char *haystack, const char *needle, int len);

int		ft_atoi(const char *str);

void	*ft_calloc(int count, int size);
char	*ft_strdup(const char *s1);

#endif
