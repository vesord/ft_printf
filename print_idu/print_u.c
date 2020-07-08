/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:32:57 by matrus            #+#    #+#             */
/*   Updated: 2020/06/18 18:32:58 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_ullen_printf(size_t nb)
{
	if (nb < 10)
		return (1);
	return (ft_ullen_printf(nb / 10) + 1);
}

size_t			print_u(t_specificator *spec, va_list *ap)
{
	t_print_idu s_prnt;

	print_u_s_prnt_init(&s_prnt, spec, ap);
	if (spec->flags & PF_FLAG_MINUS)
		print_u_spnw(&s_prnt, spec);
	else
	{
		if (spec->precision < 0 && (spec->flags & PF_FLAG_ZERO))
			print_u_swn(&s_prnt, spec);
		else
			print_u_wspn(&s_prnt, spec);
	}
	print_u_s_print_correct(&s_prnt);
	return (s_prnt.p_precision + s_prnt.p_sign + s_prnt.p_nb + s_prnt.p_width);
}

void			print_u_s_prnt_init(t_print_idu *s_prnt,
	t_specificator *spec, va_list *ap)
{
	s_prnt->nbu = get_arg_len_u(spec, ap);
	if ((spec->flags & PF_FLAG_PLUS) || (spec->flags & PF_FLAG_SPACE))
		s_prnt->p_sign = 1;
	else
		s_prnt->p_sign = 0;
	s_prnt->p_nb = ft_ullen_printf(s_prnt->nbu);
	if (spec->precision >= 0)
	{
		if (spec->precision == 0 && s_prnt->nbu == 0)
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

size_t			get_arg_len_u(t_specificator *spec, va_list *ap)
{
	size_t nb;

	if (spec->length == 'l')
		nb = va_arg(*ap, unsigned long int);
	else if (spec->length == 'L')
		nb = va_arg(*ap, unsigned long long int);
	else if (spec->length == 'h')
		nb = (unsigned short)(va_arg(*ap, unsigned int));
	else if (spec->length == 'H')
		nb = (unsigned char)(va_arg(*ap, unsigned int));
	else
		nb = va_arg(*ap, unsigned int);
	return (nb);
}

void			print_u_s_print_correct(t_print_idu *s_prnt)
{
	if (s_prnt->p_precision < 0)
		s_prnt->p_precision = 0;
	if (s_prnt->p_width < 0)
		s_prnt->p_width = 0;
}
