/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:52:45 by matrus            #+#    #+#             */
/*   Updated: 2020/06/18 18:52:49 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnb_u_nosn(size_t n)
{
	if (n > 9)
		putnb_u_nosn(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

void		print_u_sign(t_specificator *spec)
{
	if (spec->flags & PF_FLAG_PLUS)
		ft_putchar_fd('+', 1);
	else if (spec->flags & PF_FLAG_SPACE)
		ft_putchar_fd(' ', 1);
	else
		return ;
}

void		print_u_width(t_print_idu *s_prnt, t_specificator *spec)
{
	char	fill;
	ssize_t	len;

	fill = ' ';
	if (!(spec->flags & PF_FLAG_MINUS) &&
		(spec->precision < 0) && (spec->flags & PF_FLAG_ZERO))
		fill = '0';
	len = s_prnt->p_width;
	while (len > 0)
	{
		ft_putchar_fd(fill, 1);
		len--;
	}
}

void		print_u_precision(t_print_idu *s_print)
{
	ssize_t	len;

	len = s_print->p_precision;
	while (len > 0)
	{
		ft_putchar_fd('0', 1);
		len--;
	}
}

void		print_u_nb(t_print_idu *s_print)
{
	if (s_print->p_nb)
		putnb_u_nosn(s_print->nbu);
}
