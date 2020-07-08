/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:41:11 by matrus            #+#    #+#             */
/*   Updated: 2020/06/16 11:41:12 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ilen(int nb)
{
	if (nb < 0)
	{
		if (nb > -10)
			return (2);
		else
			return (ft_ilen(nb / 10 * -1) + 2);
	}
	if (nb < 10)
		return (1);
	return (ft_ilen(nb / 10) + 1);
}