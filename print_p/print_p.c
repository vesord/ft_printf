/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:51:43 by matrus            #+#    #+#             */
/*   Updated: 2020/06/19 14:51:44 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	on LINUX ft_plen() should return 5: strlen("(nil)")
**	on MAC ft_plen() should return 1: strlen("0")
*/

static size_t	ft_plen(size_t nb)
{
	size_t	mask;
	ssize_t	len;
	int		i;

	mask = 0b1111;
	i = 0;
	len = 0;
	if (nb == 0)
		return (1);
	while (i < 16)
	{
		if (nb & mask || nb > 0)
			len++;
		nb = nb >> 4;
		i++;
	}
	return (len);
}

size_t			print_p(t_specificator *spec, va_list *ap)
{
	size_t		ptr;
	size_t		ret_val;

	ptr = va_arg(*ap, size_t);
	if (spec->flags & PF_FLAG_MINUS)
		ret_val = print_p_pw(ptr, spec);
	else
		ret_val = print_p_wp(ptr, spec);
	return (ret_val);
}

size_t			print_p_pw(size_t ptr, t_specificator *spec)
{
	size_t	len;
	ssize_t	printed;

	len = ft_plen(ptr);
	write(1, "0x", 2);
	printed = 2;
	if (!(ptr == 0 && spec->precision == 0))
		printed += print_p_nb(ptr, len);
	while (printed < spec->width)
	{
		ft_putchar_fd(' ', 1);
		printed++;
	}
	return ((size_t)printed);
}

size_t			print_p_wp(size_t ptr, t_specificator *spec)
{
	ssize_t len;
	ssize_t printed;

	printed = 0;
	len = ft_plen(ptr) + 2;
	if (ptr == 0 && spec->precision == 0)
		len--;
	while (len + printed < spec->width)
	{
		ft_putchar_fd(' ', 1);
		printed++;
	}
	write(1, "0x", 2);
	printed += 2;
	len -= 2;
	printed += print_p_nb(ptr, len);
	return ((size_t)printed);
}

size_t			print_p_nb(size_t p, size_t len)
{
	size_t		ptr;
	size_t		i;
	const char	*letter;
	char		mask;

	letter = "0123456789abcdef";
	mask = 0b00001111;
	i = 0;
	while (i < len)
	{
		ptr = p;
		ptr = ptr >> ((len - i - 1) * 4);
		ft_putchar_fd(letter[(int)((char)(ptr & mask))], 1);
		i++;
	}
	return (i);
}
