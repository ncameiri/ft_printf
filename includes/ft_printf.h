/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:27:25 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/21 16:27:30 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# define FLAG "# -+'*.0123456789"
# define SYMBOL "0# -+'*."
# define SPECIFIER "cspdiuxX%"

typedef struct	s_argdata
{
	int		flags_do;
	int		width;
	int		menos;
	int		zero;
	int		ponto;
	int		asteris;
	int		precision_do;
	int		width_do;
	int		precision;
	int		hash;
	char	*flags;
	char	*length;
	char	*final_out;
}				t_argdata;
typedef struct	s_input
{
	int		ind;
	int		error;
	int		f_rt;
	int		m_in;
	char	*in;
}				t_input;
typedef struct	s_int_ctrl
{
	int i;
	int a;
	int digits;
	int neg;
	int zer_sp;
}				t_int_ctrl;
typedef struct	s_uint_ctrl
{
	unsigned int	i;
	unsigned int	a;
	int				digits;
	int				neg;
	int				zer_sp;
}				t_uint_ctrl;
void			read_precision(t_input *i_s, t_argdata *arg_data, va_list args);
char			*dex_hex_conv(unsigned long long int n);
void			input_struct_init(t_input *input_struct, char *in);
void			arg_data_init(t_argdata *arg_data);
int				white_space(t_input *i_s, t_argdata *arg_data);
void			mng_percent(va_list args, t_input *i_s, t_argdata *arg_data);
int				ft_printf (const char *input, ...);
void			print_int(va_list args, t_input *i_s, t_argdata *arg_data);
int				read_width(t_input *i_s, t_argdata *arg_data);
void			printstring(va_list args, t_input *i_s, t_argdata *arg_data);
void			printchar(va_list args, t_input *i_s, t_argdata *arg_data);
int				mng_specifier(va_list args, t_input *i_s, t_argdata *arg_data);
int				string_ret(const char *in, va_list args,
				int *index, t_argdata *arg_data);
void			print_int(va_list args, t_input *i_s, t_argdata *arg_data);
void			print_hexa(va_list args,
				t_input *i_s, t_argdata *arg_data, int cap_x);
void			print_uint(va_list args, t_input *i_s, t_argdata *arg_data);
void			print_uint(va_list args, t_input *i_s, t_argdata *arg_data);
void			ft_putuint(unsigned int n);
void			invert_str(char **str);
void			print_point(va_list args, t_input *i_s, t_argdata *arg_data);
void			mng_symbols(va_list args, t_input *i_s, t_argdata *arg_data);
void			menos(t_input *i_s, t_argdata *arg_data);
void			zero_flag(t_input *i_s, t_argdata *arg_data);
void			param_width(va_list args, t_input *i_s, t_argdata *arg_data);
void			prec_1(va_list args, t_input *i_s, t_argdata *arg_data);
void			string_nula(t_input *i_s, t_argdata *arg_data);
int				short_lines_str(t_input *i_s,
				t_argdata *arg_data, char *content);
void			zer_prec (int num, t_input *i_s);
void			nul_hex_x(t_argdata *arg_data, char **reshex);
#endif
