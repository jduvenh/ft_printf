/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduvenh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 10:02:38 by jduvenh           #+#    #+#             */
/*   Updated: 2018/08/02 20:13:09 by jduvenh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (len < n)
	{
		len += ft_wclen(src[i]);
		if (len > n)
			break ;
		dst[i] = src[i];
		dst[++i] = L'\0';
	}
	return (dst);
}
