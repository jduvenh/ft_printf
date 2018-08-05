/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduvenh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:00:50 by jduvenh           #+#    #+#             */
/*   Updated: 2018/08/05 13:20:19 by jduvenh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	specifier_position(char c, char *spec)
{
	int		pos;

	pos = 0;
	while (spec[pos])
	{
		if (c == spec[pos])
			return (pos);
		pos++;
	}
	return (-1);
}

static int	get_specifier(char c, t_attr *attr, char *spec)
{
	int		*corres;
	int		specifier;

	corres = ft_memalloc(sizeof(int) * SPECI_SIZE);
	corres[LOWER_S] = LOW_S_BIT;
	corres[UPPER_S] = UPP_S_BIT;
	corres[LOWER_P] = LOW_P_BIT;
	corres[LOWER_D] = LOW_D_BIT;
	corres[UPPER_D] = UPP_D_BIT;
	corres[LOWER_I] = LOW_I_BIT;
	corres[LOWER_O] = LOW_O_BIT;
	corres[UPPER_O] = UPP_O_BIT;
	corres[LOWER_U] = LOW_U_BIT;
	corres[UPPER_U] = UPP_U_BIT;
	corres[LOWER_X] = LOW_X_BIT;
	corres[UPPER_X] = UPP_X_BIT;
	corres[LOWER_C] = LOW_C_BIT;
	corres[UPPER_C] = UPP_C_BIT;
	corres[LOWER_B] = LOW_B_BIT;
	if (((specifier = specifier_position(c, spec)) != (-1)) && c)
		attr->flags |= corres[specifier];
	free(corres);
	return (specifier);
}

int			parse_specifier(va_list arg, char **format, t_attr *attr)
{
	int		specifier;
	int		is_valid;
	char	*conversion;

	attr->flags = 0;
	if (!(conversion = (char *)malloc(sizeof(char) * SPECI_SIZE)))
		return (0);
	conversion = ft_strncpy(conversion, SPECIFIERS, SPECI_SIZE);
	specifier = (-1);
	while (**format)
	{
		if ((specifier_position(**format, conversion) != (-1)) \
				&& (specifier = get_specifier(**format, attr, conversion)))
			break ;
		if (!(is_valid = get_attributes(format, arg, attr)))
			break ;
	}
	free(conversion);
	return (specifier);
}
