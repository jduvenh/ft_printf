/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduvenh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:46:26 by jduvenh           #+#    #+#             */
/*   Updated: 2018/08/03 23:02:26 by jduvenh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int print_specifier(char format, va_list arg, t_attr *attr, int i)
{
	int		prnt;

	if (i == LOWER_S)
		prnt = print_string(arg , attr);
	else if (i == UPPER_S)
		prnt = print_wide_string(arg, attr);
	else if ((i == LOWER_D || i == UPPER_D || i = LOWER_I) 
			|| (i == LOWER_U || i == UPPER_U))
		prnt = print_decimal(arg, attr);
	else if (i == LOWER_O || i == UPPER_O)
		prnt = print_octal(arg, attr);
	else if (i == LOWER_P || LOWER_X || i == UPPER_X)
		prnt = print_hexadecimal(arg, attr);
	else if (i == LOWER_C)
		prnt = print_character(arg, attr);
	else if (i == UPPER_C)
		prnt = print_wide_character(arg, attr);
	else if (i == LOWER_B)
		prnt = print_binary


}
