/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 15:08:13 by matrus            #+#    #+#             */
/*   Updated: 2020/06/21 15:08:14 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_ullen_printf(size_t nb)
{
	if (nb < 10)
		return (1);
	return (ft_ullen_printf(nb / 10) + 1);
}

static size_t	print_f_get_integ(double nb, char isneg)
{
	if (isneg)
		return ((size_t)-nb);
	else
		return ((size_t)nb);
}

size_t			print_f(t_specificator *spec, va_list *ap)
{
	t_print_f s_prnt;

	print_f_s_prnt_init(&s_prnt, spec, ap);
	if (spec->flags & PF_FLAG_MINUS)
		print_f_snw(&s_prnt, spec);
	else
	{
		if (spec->flags & PF_FLAG_ZERO)
			print_f_swn(&s_prnt, spec);
		else
			print_f_wsn(&s_prnt, spec);
	}
	print_f_s_print_correct(&s_prnt);
	return (s_prnt.p_precision + s_prnt.p_sign + s_prnt.p_nb + s_prnt.p_width);
}

void			print_f_s_prnt_init(t_print_f *s_prnt,
	t_specificator *spec, va_list *ap)
{
	s_prnt->nb = va_arg(*ap, double);
	if (s_prnt->nb < 0 || (spec->flags & PF_FLAG_PLUS) ||
		(spec->flags & PF_FLAG_SPACE))
		s_prnt->p_sign = 1;
	else
		s_prnt->p_sign = 0;
	if (s_prnt->nb < 0)
		s_prnt->isneg = 1;
	else
		s_prnt->isneg = 0;
	s_prnt->integ = print_f_get_integ(s_prnt->nb, s_prnt->isneg);
	s_prnt->p_nb = ft_ullen_printf(s_prnt->integ);
	if (spec->precision > 0)
		spec->precision++;
	if (spec->precision >= 0)
	{
		s_prnt->p_width = spec->width - spec->precision - s_prnt->p_nb
			- s_prnt->p_sign;
		s_prnt->p_precision = spec->precision;
	}
	else
	{
		s_prnt->p_precision = 7;
		s_prnt->p_width = spec->width - 7 - s_prnt->p_nb - s_prnt->p_sign;
	}
}

void			print_f_s_print_correct(t_print_f *s_prnt)
{
	if (s_prnt->p_precision < 0)
		s_prnt->p_precision = 0;
	if (s_prnt->p_width < 0)
		s_prnt->p_width = 0;
}
