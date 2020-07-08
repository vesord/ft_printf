/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 11:46:14 by matrus            #+#    #+#             */
/*   Updated: 2020/06/18 11:46:14 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_llen_printf(ssize_t nb)
{
	if (nb < 0)
	{
		if (nb > -10)
			return (1);
		else
			return (ft_llen_printf(nb / 10 * -1) + 1);
	}
	if (nb < 10)
		return (1);
	return (ft_llen_printf(nb / 10) + 1);
}

size_t			print_id(t_specificator *spec, va_list *ap)
{
	t_print_idu s_prnt;

	print_id_s_prnt_init(&s_prnt, spec, ap);
	if (spec->flags & PF_FLAG_MINUS)
		print_id_spnw(&s_prnt, spec);
	else
	{
		if (spec->precision < 0 && (spec->flags & PF_FLAG_ZERO))
			print_id_swn(&s_prnt, spec);
		else
			print_id_wspn(&s_prnt, spec);
	}
	print_id_s_print_correct(&s_prnt);
	return (s_prnt.p_precision + s_prnt.p_sign + s_prnt.p_nb + s_prnt.p_width);
}

void			print_id_s_prnt_init(t_print_idu *s_prnt,
	t_specificator *spec, va_list *ap)
{
	s_prnt->nb = get_arg_len_id(spec, ap);
	if (s_prnt->nb < 0 || (spec->flags & PF_FLAG_PLUS) ||
		(spec->flags & PF_FLAG_SPACE))
		s_prnt->p_sign = 1;
	else
		s_prnt->p_sign = 0;
	s_prnt->p_nb = ft_llen_printf(s_prnt->nb);
	if (spec->precision >= 0)
	{
		if (spec->precision == 0 && s_prnt->nb == 0)
			s_prnt->p_nb = 0;
		s_prnt->p_width = spec->width - ft_lmax(spec->precision, s_prnt->p_nb)
			- s_prnt->p_sign;
		s_prnt->p_precision = spec->precision - s_prnt->p_nb;
	}
	else
	{
		s_prnt->p_width = spec->width - (s_prnt->p_nb + s_prnt->p_sign);
		s_prnt->p_precision = 0;
	}
}

ssize_t			get_arg_len_id(t_specificator *spec, va_list *ap)
{
	ssize_t nb;

	if (spec->length == 'l')
		nb = va_arg(*ap, long int);
	else if (spec->length == 'L')
		nb = va_arg(*ap, long long int);
	else if (spec->length == 'h')
		nb = (short)(va_arg(*ap, int));
	else if (spec->length == 'H')
		nb = (char)(va_arg(*ap, int));
	else
		nb = va_arg(*ap, int);
	return (nb);
}

void			print_id_s_print_correct(t_print_idu *s_prnt)
{
	if (s_prnt->p_precision < 0)
		s_prnt->p_precision = 0;
	if (s_prnt->p_width < 0)
		s_prnt->p_width = 0;
}
