/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 13:56:02 by matrus            #+#    #+#             */
/*   Updated: 2020/06/19 13:56:03 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	on LINUX %% prints only 1 percentage
**	on MAC %% prints percent with width, flag '0' not ignored
*/

size_t	print_pct(t_specificator *spec)
{
	ssize_t	p_width;

	p_width = 0;
	if (spec->width)
		p_width = spec->width - 1;
	if (spec->flags & PF_FLAG_MINUS)
		print_pct_pw(p_width);
	else
		print_pct_wp(spec, p_width);
	return (p_width + 1);
}

void	print_pct_pw(ssize_t p_width)
{
	ft_putchar_fd('%', 1);
	while (p_width)
	{
		ft_putchar_fd(' ', 1);
		p_width--;
	}
}

void	print_pct_wp(t_specificator *spec, ssize_t p_width)
{
	char fill;

	fill = ' ';
	if (spec->flags & PF_FLAG_ZERO)
		fill = '0';
	while (p_width)
	{
		ft_putchar_fd(fill, 1);
		p_width--;
	}
	ft_putchar_fd('%', 1);
}
