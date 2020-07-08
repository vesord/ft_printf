/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 11:51:26 by matrus            #+#    #+#             */
/*   Updated: 2020/06/18 11:51:27 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnb_nosn(ssize_t n)
{
	if (n < 0)
	{
		if (n < -9)
			putnb_nosn(n / 10 * -1);
		ft_putchar_fd(n % 10 * -1 + '0', 1);
		return ;
	}
	if (n > 9)
		putnb_nosn(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

void		print_id_sign(t_print_idu *s_prnt, t_specificator *spec)
{
	if (s_prnt->nb < 0)
		ft_putchar_fd('-', 1);
	else if (spec->flags & PF_FLAG_PLUS)
		ft_putchar_fd('+', 1);
	else if (spec->flags & PF_FLAG_SPACE)
		ft_putchar_fd(' ', 1);
	else
		return ;
}

void		print_id_width(t_print_idu *s_prnt, t_specificator *spec)
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

void		print_id_precision(t_print_idu *s_print)
{
	ssize_t	len;

	len = s_print->p_precision;
	while (len > 0)
	{
		ft_putchar_fd('0', 1);
		len--;
	}
}

void		print_id_nb(t_print_idu *s_print)
{
	if (s_print->p_nb)
		putnb_nosn(s_print->nb);
}
