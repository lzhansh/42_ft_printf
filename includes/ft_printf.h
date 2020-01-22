/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:43:15 by lzhansha          #+#    #+#             */
/*   Updated: 2019/07/02 12:59:27 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

# define FLAGS "-+ #*.0123456789hlLz"

typedef struct	s_flag
{
	int			minus;
	int			plus;
	int			neg;
	int			sp;
	int			hash;
	int			zero;
	int			prec;
	int			width;
	int			dr;
	int			pos;
}				t_flag;

typedef enum	e_len_mod
{
	pf_mod = 0,
	pf_h,
	pf_hh,
	pf_l,
	pf_ll,
	pf_z,
	pf_L
}				t_len_mod;

typedef struct	s_list
{
	va_list		ap;
	char		*out;
	t_len_mod	mod;
	t_flag		flag;
	int			fd;
	int			i;
	int			ret;
}				t_list;

int				ft_printf(const char *format, ...);

void			ft_extra(const char *format, t_list *env);
void			ft_extra_color(const char *format, t_list *env);

void			ft_convert_width(t_list *env);
void			ft_convert_prec(const char *f, t_list *env);
void			ft_convert_flag(const char *f, t_list *env);
void			ft_convert_spec(const char *f, t_list *env);
void			ft_convert(const char *f, t_list *env);

void			ft_flag_init(t_flag *f);
void			ft_flag_len_mod(const char *f, t_list *env);
void			ft_flag_perc(t_list *env);

void			ft_check_int(t_list *env);
void			ft_check_unsint(t_list *env);
void			ft_check_char(t_list *env, char t);
void			ft_check_lchar(t_list *env, char t);
void			ft_check_ptr(t_list *env);

void			ft_check_numb(t_list *env, char t);
void			ft_check_double(t_list *env, char t);

void			ft_print_nonprnt(t_list *env);

void			ft_print_null_s(t_list *env);
void			ft_print_null_c(t_list *env);
void			ft_print_c(t_list *env, char c);
void			ft_print_s(t_list *env);

void			ft_print_ptr(t_list *env);

void			ft_print_numb(t_list *env, char t, long int num);

void			ft_print_digits(t_list *env);
void			ft_print_digits_neg(t_list *env);

void			ft_print_f(t_list *env, long double ld);
long			ft_print_f_num(t_list *env, long double ld, int p);
void			ft_print_f_prec(t_list *env, long double ld);
void			ft_print_feg_width(t_list *env);

void			ft_print_e(t_list *env, long double ld, char t);
long			ft_print_e_num(long double ld, int p);
void			ft_print_e_exp(long double ld, char t, char **let);
char			*ft_print_efg_str(char *str1, int pnt, int end, int hash);
void			ft_print_e_prec(t_list *env, long double ld, char t);

void			ft_print_g(t_list *env, long double ld, char t);
void			ft_print_g_check(t_list *env, long double ld, char t);
void			ft_print_g_f(t_list *env, long double ld, int end);
void			ft_print_g_e(t_list *env, long double ld, char t, int p);
void			ft_print_g_del(char *tmp);

#endif
