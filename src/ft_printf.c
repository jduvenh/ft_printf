/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduvenh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 10:21:12 by jduvenh           #+#    #+#             */
/*   Updated: 2018/08/03 13:46:02 by jduvenh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift.h"
#include "ft_printf.h"

static int	print_stdout(const char **format, va_list arg);
{
	int		spf;
	t_attr	attri;
	
	attri.precison = 0;
	attri.width = 0;
	attri.flags = 0;
	spf = parse_specifier(arg, (char **)format, &attri);
	if (!**format)
	{
		return (-1);
	}
	return (print_specifier((char)**format, arg, &attr, spf));

}

int		ft_printf(const char *format, ...)
{
	int		len;
	int		count;
	va_list	arg;

	va_start(arg, format);
	count  = 0;
	while (format != '\0')
	{
		if (*format == '%')
		{
			++format;
			if ((len = print_stdout(&format, arg)) == (-1))
				break ;
			count = ( count + len);
		}
		else 
		{
			write(1, &format, 1);
			++count;
		}
		++format;
	}
	va_end(arg);
	return(count);
}
