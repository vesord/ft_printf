/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 11:52:45 by matrus            #+#    #+#             */
/*   Updated: 2020/06/18 11:52:46 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int				ft_printf(const char *fmt, ...);

typedef struct	s_specificator
{
	char	flags;
	ssize_t	width;
	ssize_t	precision;
	char	length;
	char	type;
}				t_specificator;

# define PF_FLAG_MINUS	0b00000001
# define PF_FLAG_PLUS	0b00000010
# define PF_FLAG_SPACE	0b00000100
# define PF_FLAG_OCTOT	0b00001000
# define PF_FLAG_ZERO	0b00010000

t_specificator	*new_spec();
void			reset_spec(t_specificator *spec);
size_t			print_spec(t_specificator *specificator, va_list *ap);
size_t			set_spec(const char *fmt, t_specificator *spec, va_list *ap);

size_t			try_parse_flags(const char *fmt, t_specificator *spec);
size_t			try_parse_width(const char *fmt, t_specificator *spec,
	va_list *ap);
size_t			try_parse_precision(const char *fmt, t_specificator *spec,
	va_list *ap);
size_t			try_parse_length(const char *fmt, t_specificator *spec);
size_t			try_parse_type(const char *fmt, t_specificator *spec);

/*
**	PRINT TYPES 'i' AND 'd'
*/

typedef struct	s_print_idu
{
	ssize_t		nb;
	size_t		nbu;
	ssize_t		p_sign;
	ssize_t		p_width;
	ssize_t		p_precision;
	ssize_t		p_nb;
}				t_print_idu;

size_t			print_id(t_specificator *spec, va_list *ap);
void			print_id_s_prnt_init(t_print_idu *s_prnt, t_specificator *spec,
	va_list *ap);
void			print_id_s_print_correct(t_print_idu *s_prnt);
ssize_t			get_arg_len_id(t_specificator *spec, va_list *ap);

void			print_id_spnw(t_print_idu *s_prnt, t_specificator *spec);
void			print_id_wspn(t_print_idu *s_prnt, t_specificator *spec);
void			print_id_swn(t_print_idu *s_prnt, t_specificator *spec);

void			print_id_nb(t_print_idu *s_print);
void			print_id_precision(t_print_idu *s_print);
void			print_id_width(t_print_idu *s_prnt, t_specificator *spec);
void			print_id_sign(t_print_idu *s_prnt, t_specificator *spec);

/*
**	PRINT TYPES 'u'
*/

size_t			print_u(t_specificator *spec, va_list *ap);
void			print_u_s_prnt_init(t_print_idu *s_prnt, t_specificator *spec,
	va_list *ap);
void			print_u_s_print_correct(t_print_idu *s_prnt);
size_t			get_arg_len_u(t_specificator *spec, va_list *ap);

void			print_u_wspn(t_print_idu *s_prnt, t_specificator *spec);
void			print_u_swn(t_print_idu *s_prnt, t_specificator *spec);
void			print_u_spnw(t_print_idu *s_prnt, t_specificator *spec);

void			print_u_nb(t_print_idu *s_print);
void			print_u_precision(t_print_idu *s_print);
void			print_u_width(t_print_idu *s_prnt, t_specificator *spec);
void			print_u_sign(t_specificator *spec);

/*
**	PRINT TYPE 'c'
*/

size_t			print_c(t_specificator *spec, va_list *ap);
void			print_c_cw(char c, t_specificator *spec);
void			print_c_wc(char c, t_specificator *spec);

/*
**	PRINT TYPE 's'
*/

size_t			print_s(t_specificator *spec, va_list *ap);
size_t			print_s_sw(const char *str, t_specificator *spec);
size_t			print_s_ws(const char *str, t_specificator *spec);

/*
**	PRINT TYPE 'x' AND 'X'
*/

typedef struct	s_print_xx
{
	size_t		nbx;
	ssize_t		p_x;
	ssize_t		p_width;
	ssize_t		p_precision;
	ssize_t		p_nb;
}				t_print_xx;

size_t			print_xx(t_specificator *spec, va_list *ap);
void			print_xx_s_prnt_init(t_print_xx *s_prnt, t_specificator *spec,
	va_list *ap);
void			print_xx_s_print_correct(t_print_xx *s_prnt);
size_t			get_arg_len_x(t_specificator *spec, va_list *ap);

void			print_xx_spnw(t_print_xx *s_prnt, t_specificator *spec);
void			print_xx_swn(t_print_xx *s_prnt, t_specificator *spec);
void			print_xx_wspn(t_print_xx *s_prnt, t_specificator *spec);

void			print_xx_nb(t_print_xx *s_prnt, t_specificator *spec);
void			print_xx_width(t_print_xx *s_prnt, t_specificator *spec);
void			print_xx_precision(t_print_xx *s_prnt);
void			print_xx_x(t_print_xx *s_prnt, t_specificator *spec);

/*
**	PRINT TYPE '%'
*/

size_t			print_pct(t_specificator *spec);
void			print_pct_wp(t_specificator *spec, ssize_t p_width);
void			print_pct_pw(ssize_t p_width);

/*
**	PRINT TYPE 'p'
*/

size_t			print_p(t_specificator *spec, va_list *ap);
size_t			print_p_wp(size_t ptr, t_specificator *spec);
size_t			print_p_pw(size_t ptr, t_specificator *spec);
size_t			print_p_nb(size_t p, size_t len);

/*
**	PRINT TYPE 'f' REDUCED
*/

typedef struct	s_print_f
{
	double		nb;
	char		isneg;
	size_t		integ;
	ssize_t		p_sign;
	ssize_t		p_width;
	ssize_t		p_precision;
	ssize_t		p_nb;
}				t_print_f;

size_t			print_f(t_specificator *spec, va_list *ap);
void			print_f_s_prnt_init(t_print_f *s_prnt, t_specificator *spec,
	va_list *ap);
void			print_f_s_print_correct(t_print_f *s_prnt);

void			print_f_snw(t_print_f *s_prnt, t_specificator *spec);
void			print_f_swn(t_print_f *s_prnt, t_specificator *spec);
void			print_f_wsn(t_print_f *s_prnt, t_specificator *spec);

void			print_f_sign(t_print_f *s_prnt, t_specificator *spec);
void			print_f_nb(t_print_f *s_prnt);
void			print_f_width(t_print_f *s_prnt, t_specificator *spec);

#endif
