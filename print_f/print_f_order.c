/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:36:28 by matrus            #+#    #+#             */
/*   Updated: 2020/06/21 16:36:29 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_f_snw(t_print_f *s_prnt, t_specificator *spec)
{
	print_f_sign(s_prnt, spec);
	print_f_nb(s_prnt);
	print_f_width(s_prnt, spec);
}

void	print_f_swn(t_print_f *s_prnt, t_specificator *spec)
{
	print_f_sign(s_prnt, spec);
	print_f_width(s_prnt, spec);
	print_f_nb(s_prnt);
}

void	print_f_wsn(t_print_f *s_prnt, t_specificator *spec)
{
	print_f_width(s_prnt, spec);
	print_f_sign(s_prnt, spec);
	print_f_nb(s_prnt);
}
