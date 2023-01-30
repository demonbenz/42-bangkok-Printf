/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:04:01 by otangkab          #+#    #+#             */
/*   Updated: 2022/09/13 18:31:08 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->t_len += write(1, &c, 1);
}

void	ft_print_s(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
	i++;
	}
}

void	ft_print_string(t_print *tab)
{
	char	*s;
	int		i;

	s = va_arg(tab->args, char *);
	i = 0;
	if (s == NULL)
	{
		ft_print_s("(null)");
		tab->t_len += 6;
		return ;
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
	i++;
	}
	tab->t_len += i;
}

void	ft_print_int(t_print *tab)
{
	char	*str;	
	int		num;
	int		i;

	num = va_arg(tab->args, int);
	str = ft_itoa(num);
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
	i++;
	}
	tab->t_len += i;
	free(str);
}

void	ft_print_u_int(t_print *tab)
{
	char	*str;
	int		i;

	str = ft_unsitoa(va_arg(tab->args, unsigned int));
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
	i++;
	}
	tab->t_len += i;
	free(str);
}
