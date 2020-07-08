/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 20:07:07 by matrus            #+#    #+#             */
/*   Updated: 2020/06/14 20:07:08 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *fmt, ...)
{
	va_list			ap;
	size_t			printed;
	t_specificator	*spec;

	printed = 0;
	if (!(spec = new_spec()))
		return (-1);
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += set_spec(fmt, spec, &ap);
			printed += print_spec(spec, &ap);
		}
		else
		{
			write(1, fmt, 1);
			printed++;
			fmt++;
		}
	}
	va_end(ap);
	free(spec);
	return (printed);
}

t_specificator	*new_spec(void)
{
	t_specificator *new_spec;

	if (!(new_spec = (t_specificator *)malloc(sizeof(t_specificator))))
		return (NULL);
	new_spec->type = 0;
	new_spec->length = 0;
	new_spec->precision = -1;
	new_spec->width = 0;
	new_spec->flags = 0;
	return (new_spec);
}

void			reset_spec(t_specificator *spec)
{
	spec->type = 0;
	spec->length = 0;
	spec->precision = -1;
	spec->width = 0;
	spec->flags = 0;
}

size_t			print_spec(t_specificator *spec, va_list *ap)
{
	if (spec->type == 'i' || spec->type == 'd')
		return (print_id(spec, ap));
	else if (spec->type == 'c')
		return (print_c(spec, ap));
	else if (spec->type == 's')
		return (print_s(spec, ap));
	else if (spec->type == 'u')
		return (print_u(spec, ap));
	else if (spec->type == 'x' || spec->type == 'X')
		return (print_xx(spec, ap));
	else if (spec->type == '%')
		return (print_pct(spec));
	else if (spec->type == 'p')
		return (print_p(spec, ap));
	else if (spec->type == 'f')
		return (print_f(spec, ap));
	return (0);
}

size_t			set_spec(const char *fmt, t_specificator *spec, va_list *ap)
{
	size_t	shift;

	reset_spec(spec);
	shift = 1;
	shift += try_parse_flags(fmt + shift, spec);
	shift += try_parse_width(fmt + shift, spec, ap);
	shift += try_parse_precision(fmt + shift, spec, ap);
	shift += try_parse_length(fmt + shift, spec);
	shift += try_parse_type(fmt + shift, spec);
	return (shift);
}
