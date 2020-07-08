/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:36:20 by matrus            #+#    #+#             */
/*   Updated: 2020/06/21 16:36:22 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnb_f_integ(size_t n)
{
	if (n > 9)
		putnb_f_integ(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

void		print_f_sign(t_print_f *s_prnt, t_specificator *spec)
{
	if (s_prnt->nb < 0.)
		ft_putchar_fd('-', 1);
	else if (spec->flags & PF_FLAG_PLUS)
		ft_putchar_fd('+', 1);
	else if (spec->flags & PF_FLAG_SPACE)
		ft_putchar_fd(' ', 1);
	else
		return ;
}

void		print_f_nb(t_print_f *s_prnt)
{
	double	fract;
	size_t	i;
	double	sign;

	sign = 1.;
	if (s_prnt->isneg)
		sign = -1.;
	putnb_f_integ(s_prnt->integ);
	if (s_prnt->p_precision > 0)
	{
		fract = (s_prnt->nb * sign) - (size_t)(s_prnt->nb * sign);
		i = s_prnt->p_precision - 1;
		ft_putchar_fd('.', 1);
		while (i)
		{
			fract *= 10.;
			ft_putchar_fd((size_t)fract % 10 + '0', 1);
			i--;
		}
	}
}

void		print_f_width(t_print_f *s_prnt, t_specificator *spec)
{
	char	fill;
	ssize_t	len;

	fill = ' ';
	if (spec->flags & PF_FLAG_ZERO)
		fill = '0';
	len = s_prnt->p_width;
	while (len > 0)
	{
		ft_putchar_fd(fill, 1);
		len--;
	}
}
