/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:31:04 by matrus            #+#    #+#             */
/*   Updated: 2020/06/16 11:31:05 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MIN_LONG_DIV_TEN -922337203685477580
#define MAX_LONG_DIV_TEN 922337203685477580
#define MAX_LONG_ATOI 9223372036854775807
#define MIN_LONG_ATOI -9223372036854775807

static int		ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static ssize_t	ft_read_nb_atol(const char *str, int sign)
{
	long long	res;
	size_t		i;

	i = 0;
	res = 0;
	while (str[i] != '\0')
		if ((str[i] >= '0') && (str[i]) <= '9')
		{
			if (res * sign <= MAX_LONG_DIV_TEN
				&& res * sign >= MIN_LONG_DIV_TEN)
				res *= 10;
			else
				return (res * sign < 0 ? 0 : -1);
			if (res * sign <= MAX_LONG_ATOI - (str[i] - '0')
				&& res * sign >= MIN_LONG_ATOI - 1 + (str[i] - '0'))
				res += str[i] - '0';
			else
				return (res * sign < 0 ? 0 : -1);
			i++;
		}
		else
			break ;
	return (res * sign);
}

ssize_t			ft_atol(const char *nptr)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	while (ft_is_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (nptr[i] == '+')
		i++;
	return (ft_read_nb_atol(nptr + i, sign));
}
