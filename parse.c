/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 20:04:08 by matrus            #+#    #+#             */
/*   Updated: 2020/06/14 20:04:11 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	try_parse_flags(const char *fmt, t_specificator *spec)
{
	char	f;
	size_t	shift;

	f = 1;
	shift = 0;
	while (f)
	{
		if (*fmt == '-')
			spec->flags = spec->flags | PF_FLAG_MINUS;
		else if (*fmt == '+')
			spec->flags = spec->flags | PF_FLAG_PLUS;
		else if (*fmt == ' ')
			spec->flags = spec->flags | PF_FLAG_SPACE;
		else if (*fmt == '#')
			spec->flags = spec->flags | PF_FLAG_OCTOT;
		else if (*fmt == '0')
			spec->flags = spec->flags | PF_FLAG_ZERO;
		else
			f = 0;
		fmt++;
		if (f)
			shift++;
	}
	return (shift);
}

size_t	try_parse_width(const char *fmt, t_specificator *spec, va_list *ap)
{
	if (*fmt == '*')
	{
		if ((spec->width = va_arg(*ap, int)) < 0)
		{
			spec->width = -spec->width;
			spec->flags = spec->flags | PF_FLAG_MINUS;
		}
		return (1);
	}
	if (*fmt >= '1' && *fmt <= '9')
	{
		spec->width = ft_atol(fmt);
		return (ft_ullen(spec->width));
	}
	else
		return (0);
}

size_t	try_parse_precision(const char *fmt, t_specificator *spec, va_list *ap)
{
	size_t skip;

	skip = 0;
	if (*fmt == '.')
	{
		fmt++;
		spec->precision = 0;
	}
	else
		return (0);
	if (*fmt == '*')
	{
		if ((spec->precision = va_arg(*ap, int)) < 0)
			spec->precision = -1;
		return (2);
	}
	if (*fmt >= '0' && *fmt <= '9')
	{
		spec->precision = ft_atol(fmt);
		while (*(fmt + skip) >= '0' && *(fmt + skip) <= '9')
			skip++;
		return (skip + 1);
	}
	else
		return (1);
}

size_t	try_parse_length(const char *fmt, t_specificator *spec)
{
	if (*fmt == 'l')
	{
		if (*(fmt + 1) == 'l')
		{
			spec->length = 'L';
			return (2);
		}
		else
			spec->length = 'l';
		return (1);
	}
	if (*fmt == 'h')
	{
		if (*(fmt + 1) == 'h')
		{
			spec->length = 'H';
			return (2);
		}
		else
			spec->length = 'h';
		return (1);
	}
	return (0);
}

size_t	try_parse_type(const char *fmt, t_specificator *spec)
{
	if (*fmt == 'i')
		spec->type = 'i';
	else if (*fmt == 'd')
		spec->type = 'd';
	else if (*fmt == 'c')
		spec->type = 'c';
	else if (*fmt == 's')
		spec->type = 's';
	else if (*fmt == 'p')
		spec->type = 'p';
	else if (*fmt == 'u')
		spec->type = 'u';
	else if (*fmt == 'x')
		spec->type = 'x';
	else if (*fmt == 'X')
		spec->type = 'X';
	else if (*fmt == '%')
		spec->type = '%';
	else if (*fmt == 'f')
		spec->type = 'f';
	else
		return (0);
	return (1);
}
