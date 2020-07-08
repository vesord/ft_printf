/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 10:24:22 by matrus            #+#    #+#             */
/*   Updated: 2020/06/19 10:24:24 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_xlen(size_t nb)
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

size_t			print_xx(t_specificator *spec, va_list *ap)
{
	t_print_xx s_prnt;

	print_xx_s_prnt_init(&s_prnt, spec, ap);
	if (spec->flags & PF_FLAG_MINUS)
		print_xx_spnw(&s_prnt, spec);
	else
	{
		if (spec->precision < 0 && (spec->flags & PF_FLAG_ZERO))
			print_xx_swn(&s_prnt, spec);
		else
			print_xx_wspn(&s_prnt, spec);
	}
	print_xx_s_print_correct(&s_prnt);
	return (s_prnt.p_precision + s_prnt.p_x + s_prnt.p_nb + s_prnt.p_width);
}

void			print_xx_s_prnt_init(t_print_xx *s_prnt, t_specificator *spec,
	va_list *ap)
{
	s_prnt->nbx = get_arg_len_x(spec, ap);
	s_prnt->p_x = 0;
	if (s_prnt->nbx != 0 && (spec->flags & PF_FLAG_OCTOT))
		s_prnt->p_x = 2;
	s_prnt->p_nb = ft_xlen(s_prnt->nbx);
	if (spec->precision >= 0)
	{
		if (spec->precision == 0 && s_prnt->nbx == 0)
			s_prnt->p_nb = 0;
		s_prnt->p_width = spec->width - ft_lmax(spec->precision, s_prnt->p_nb) -
			s_prnt->p_x;
		s_prnt->p_precision = spec->precision - s_prnt->p_nb;
	}
	else
	{
		s_prnt->p_width = spec->width - s_prnt->p_nb - s_prnt->p_x;
		s_prnt->p_precision = 0;
	}
}

size_t			get_arg_len_x(t_specificator *spec, va_list *ap)
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

void			print_xx_s_print_correct(t_print_xx *s_prnt)
{
	if (s_prnt->p_precision < 0)
		s_prnt->p_precision = 0;
	if (s_prnt->p_width < 0)
		s_prnt->p_width = 0;
}
