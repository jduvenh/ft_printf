/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduvenh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:09:49 by jduvenh           #+#    #+#             */
/*   Updated: 2018/08/05 13:19:45 by jduvenh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	nbr_digits(intmax_t nbr)
{
	int		len;

	if (!nbr)
		return (1);
	len = nbr < 0 ? 1 : 0;
	while (nbr)
	{
		nbr /= 10;
		len += 1;
	}
	return (len);
}

static void	put_sign(intmax_t nbr, int attr)
{
	char	sign;

	sign = 0;
	if (nbr < 0)
		sign = '-';
	else if (nbr >= 0)
	{
		if (attr & PLUS)
			sign = '+';
		else if (attr & SPACE)
			sign = ' ';
	}
	if (sign)
		write(1, &sign, 1);
}

int			format_signed(intmax_t nbr, t_attr *attr)
{
	int		len;
	int		sign;
	int		nbr_zeros;
	int		nbr_spaces;

	len = 0;
	sign = (nbr >= 0 && (attr->flags & PLUS || attr->flags & SPACE)) ? 1 : 0;
	if (!(attr->flags & PRECISION) || attr->precision || nbr)
		len = nbr_digits(nbr);
	len += sign;
	nbr_zeros = get_nbr_zeroes(attr, &len, (nbr < 0 || sign));
	nbr_spaces = get_nbr_spaces(attr->flags, attr->width, &len);
	!(attr->flags & MINUS) ? ft_putnchar(' ', nbr_spaces) : 0;
	put_sign(nbr, attr->flags);
	ft_putnchar('0', nbr_zeros);
	if (!(attr->flags & PRECISION && !attr->precision && !nbr))
		ft_putunbr((nbr < 0) ? (-nbr) : (nbr));
	(attr->flags & MINUS) ? ft_putnchar(' ', nbr_spaces) : 0;
	return (len);
}
