/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:39:13 by matrus            #+#    #+#             */
/*   Updated: 2020/06/18 14:39:14 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_c(t_specificator *spec, va_list *ap)
{
	char ch;

	ch = va_arg(*ap, int);
	if (spec->flags & PF_FLAG_MINUS)
		print_c_cw(ch, spec);
	else
		print_c_wc(ch, spec);
	if (spec->width)
		return (spec->width);
	else
		return (1);
}

void	print_c_cw(char ch, t_specificator *spec)
{
	size_t width;

	width = spec->width;
	ft_putchar_fd(ch, 1);
	if (width)
		width--;
	while (width)
	{
		ft_putchar_fd(' ', 1);
		width--;
	}
}

void	print_c_wc(char ch, t_specificator *spec)
{
	size_t width;

	width = spec->width;
	if (width)
		width--;
	while (width)
	{
		ft_putchar_fd(' ', 1);
		width--;
	}
	ft_putchar_fd(ch, 1);
}
