/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 11:49:24 by matrus            #+#    #+#             */
/*   Updated: 2020/06/19 11:49:26 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_xx_spnw(t_print_xx *s_prnt, t_specificator *spec)
{
	print_xx_x(s_prnt, spec);
	print_xx_precision(s_prnt);
	print_xx_nb(s_prnt, spec);
	print_xx_width(s_prnt, spec);
}

void	print_xx_swn(t_print_xx *s_prnt, t_specificator *spec)
{
	print_xx_x(s_prnt, spec);
	print_xx_width(s_prnt, spec);
	print_xx_nb(s_prnt, spec);
}

void	print_xx_wspn(t_print_xx *s_prnt, t_specificator *spec)
{
	print_xx_width(s_prnt, spec);
	print_xx_x(s_prnt, spec);
	print_xx_precision(s_prnt);
	print_xx_nb(s_prnt, spec);
}
