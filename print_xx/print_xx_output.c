/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 11:53:54 by matrus            #+#    #+#             */
/*   Updated: 2020/06/19 11:53:56 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_xx_x(t_print_xx *s_prnt, t_specificator *spec)
{
	if (s_prnt->p_x)
	{
		ft_putchar_fd('0', 1);
		if (spec->type == 'x')
			ft_putchar_fd('x', 1);
		else
			ft_putchar_fd('X', 1);
	}
}

void	print_xx_precision(t_print_xx *s_prnt)
{
	ssize_t	len;

	len = s_prnt->p_precision;
	while (len > 0)
	{
		ft_putchar_fd('0', 1);
		len--;
	}
}

void	print_xx_width(t_print_xx *s_prnt, t_specificator *spec)
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

void	print_xx_nb(t_print_xx *s_prnt, t_specificator *spec)
{
	size_t		nb;
	ssize_t		i;
	const char	*letter;
	char		mask;

	if (spec->type == 'x')
		letter = "0123456789abcdef";
	else
		letter = "0123456789ABCDEF";
	mask = 0b00001111;
	i = 0;
	while (i < s_prnt->p_nb)
	{
		nb = s_prnt->nbx;
		nb = nb >> ((s_prnt->p_nb - i - 1) * 4);
		ft_putchar_fd(letter[(int)((char)(nb & mask))], 1);
		i++;
	}
}
