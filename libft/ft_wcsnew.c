/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduvenh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 10:19:41 by jduvenh           #+#    #+#             */
/*   Updated: 2018/08/02 20:14:55 by jduvenh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wcsnew(size_t size)
{
	wchar_t	*wcs;

	wcs = ft_memalloc(sizeof(wchar_t) * size + sizeof(wchar_t));
	return (wcs);
}
