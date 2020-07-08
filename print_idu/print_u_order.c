/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:48:02 by matrus            #+#    #+#             */
/*   Updated: 2020/06/18 18:48:03 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u_spnw(t_print_idu *s_prnt, t_specificator *spec)
{
	print_u_sign(spec);
	print_u_precision(s_prnt);
	print_u_nb(s_prnt);
	print_u_width(s_prnt, spec);
}

void	print_u_swn(t_print_idu *s_prnt, t_specificator *spec)
{
	print_u_sign(spec);
	print_u_width(s_prnt, spec);
	print_u_nb(s_prnt);
}

void	print_u_wspn(t_print_idu *s_prnt, t_specificator *spec)
{
	print_u_width(s_prnt, spec);
	print_u_sign(spec);
	print_u_precision(s_prnt);
	print_u_nb(s_prnt);
}
