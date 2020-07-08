/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 11:49:14 by matrus            #+#    #+#             */
/*   Updated: 2020/06/18 11:49:15 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_id_spnw(t_print_idu *s_prnt, t_specificator *spec)
{
	print_id_sign(s_prnt, spec);
	print_id_precision(s_prnt);
	print_id_nb(s_prnt);
	print_id_width(s_prnt, spec);
}

void	print_id_swn(t_print_idu *s_prnt, t_specificator *spec)
{
	print_id_sign(s_prnt, spec);
	print_id_width(s_prnt, spec);
	print_id_nb(s_prnt);
}

void	print_id_wspn(t_print_idu *s_prnt, t_specificator *spec)
{
	print_id_width(s_prnt, spec);
	print_id_sign(s_prnt, spec);
	print_id_precision(s_prnt);
	print_id_nb(s_prnt);
}
