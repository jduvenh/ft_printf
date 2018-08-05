/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduvenh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:56:06 by jduvenh           #+#    #+#             */
/*   Updated: 2018/08/05 12:53:59 by jduvenh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <wchar.h>
# include <stdlib.h>
# include <stdint.h>

# define FT_BIT(x) (1 << (x))

void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putunbr(uintmax_t n);
char				*ft_strrev(char *str);
char				*ft_str_to_lowcase(char *str);
void				ft_putnchar(char c, int n);
int					ft_wclen(wchar_t wchar);
size_t				ft_wcslen(wchar_t *wstr);
wchar_t				*ft_wcsdup(wchar_t *src);
wchar_t				*ft_wcscpy(wchar_t *dst, const wchar_t *src);
wchar_t				*ft_wcsnew(size_t size);
wchar_t				*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n);
int					ft_putwstr(wchar_t *str);
int					ft_putwchar(wchar_t c);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcat(char *s1, const char *s2);

#endif
