/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:53:55 by otangkab          #+#    #+#             */
/*   Updated: 2022/09/13 18:07:41 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_init_tab(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->sign = 0;
	tab->t_len = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->percent = 0;
	tab->space = 0;
	return (tab);
}

void	ft_print_output(t_print *tab, const char *str, int pos)
{
	if (str[pos] == 'c')
		ft_print_char(tab);
	else if (str[pos] == 's')
		ft_print_string(tab);
	else if (str[pos] == 'p')
		ft_print_address(tab);
	else if ((str[pos] == 'd') || (str[pos] == 'i'))
		ft_print_int(tab);
	else if (str[pos] == 'u')
		ft_print_u_int(tab);
	else if (str[pos] == '%')
		ft_print_perc(tab);
	else if (str[pos] == 'x')
		ft_print_hex(tab, 0);
	else if (str[pos] == 'X')
		ft_print_hex(tab, 1);
}

int	ft_format_cal(t_print *tab, const char *str, int pos)
{
	while ((str[pos] != 'c') && (str[pos] != 's') && (str[pos] != 'p') \
			&& (str[pos] != 'd') && (str[pos] != 'i') \
			&& (str[pos] != 'u') && (str[pos] != 'x') \
			&& (str[pos] != 'X') && (str[pos] != '%'))
	{
		if (str[pos] == '.')
		{
			tab->point = 1;
		}
		if (str[pos] == '-')
		{
			tab->dash = 1;
		}
		if (str[pos] == ' ')
		{
			tab->space = 1;
		}
		if (str[pos] == '+')
		{
			tab->sign = 1;
		}
		pos++;
	}
	ft_print_output(tab, str, pos);
	return (pos);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_init_tab(tab);
	va_start(tab->args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i = ft_format_cal(tab, format, i + 1);
		}
		else
			ret += write(1, &format[i], 1);
	i++;
	}
	va_end(tab->args);
	ret += tab->t_len;
	free(tab);
	return (ret);
}
