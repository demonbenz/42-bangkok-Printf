/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:41:50 by otangkab          #+#    #+#             */
/*   Updated: 2022/09/11 03:17:11 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stddef.h>
# include<stdlib.h>
# include<stdarg.h>
# include "libft.h"

typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	int		zero;
	int		point;
	int		dash;
	int		t_len;
	int		sign;
	int		is_zero;
	int		percent;
	int		space;
}	t_print;

int		ft_printf(const char *format, ...);

void	ft_print_char(t_print *tab);
void	ft_print_string(t_print *tab);
void	ft_print_int(t_print *tab);
void	ft_print_u_int(t_print *tab);
void	ft_print_perc(t_print *tab);

int		hex_len(unsigned long num);
char	*ft_turn_hex(unsigned long ul);
char	*ft_prefix(char *str);

void	ft_print_address(t_print *tab);
void	ft_print_hex(t_print *tab, int upper);

char	*ft_unsitoa(unsigned int n);

#endif
