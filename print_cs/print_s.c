/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:45:32 by matrus            #+#    #+#             */
/*   Updated: 2020/06/18 16:45:33 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	on LINUX null_str should be "\0" in case of small precision
**	on MAC null_str should be "(null)\0" in case of cutting by precision
*/

size_t	print_s(t_specificator *spec, va_list *ap)
{
	const char	*str;
	const char	*null_str;
	size_t		ret_val;

	if (spec->precision >= 6 || spec->precision < 0)
		null_str = "(null)\0";
	else
		null_str = "(null)\0";
	str = va_arg(*ap, const char *);
	if (!str)
		str = null_str;
	if (spec->flags & PF_FLAG_MINUS)
		ret_val = print_s_sw(str, spec);
	else
		ret_val = print_s_ws(str, spec);
	return (ret_val);
}

size_t	print_s_sw(const char *str, t_specificator *spec)
{
	ssize_t p_len;
	ssize_t printed;

	printed = 0;
	p_len = ft_strlen(str);
	if (spec->precision >= 0)
		p_len = ft_lmin(spec->precision, p_len);
	while (*str && p_len)
	{
		ft_putchar_fd(*(str++), 1);
		printed++;
		p_len--;
	}
	while (printed < spec->width)
	{
		ft_putchar_fd(' ', 1);
		printed++;
	}
	return ((size_t)printed);
}

size_t	print_s_ws(const char *str, t_specificator *spec)
{
	ssize_t p_len;
	ssize_t printed;

	printed = 0;
	p_len = ft_strlen(str);
	if (spec->precision >= 0)
		p_len = ft_lmin(spec->precision, p_len);
	while (printed + p_len < spec->width)
	{
		ft_putchar_fd(' ', 1);
		printed++;
	}
	while (*str && p_len)
	{
		ft_putchar_fd(*(str++), 1);
		printed++;
		p_len--;
	}
	return ((size_t)printed);
}
