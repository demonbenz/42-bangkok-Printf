/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:11:21 by otangkab          #+#    #+#             */
/*   Updated: 2022/09/20 15:17:20 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	hex_len(unsigned long num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0)
	{
		num = num / 16;
	i++;
	}
	return (i);
}

void	ft_strrev(char *str)
{
	char	c;
	int		i;
	int		n;

	n = ft_strlen(str);
	i = 0;
	while (i < n / 2)
	{
		c = str[n - i - 1];
		str[n - i - 1] = str[i];
		str[i] = c;
	i++;
	}
}

char	*ft_turn_hex(unsigned long ul)
{
	char	*str;
	char	*hex_set;
	int		i;

	hex_set = "0123456789abcdef";
	str = ft_calloc(sizeof(char), hex_len(ul) + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	i = 0;
	while (ul > 0)
	{
		str[i] = hex_set[ul % 16];
		ul = ul / 16;
	i++;
	}
	ft_strrev(str);
	return (str);
}

void	ft_print_address(t_print *tab)
{
	char	*hex;
	int		i;

	hex = ft_turn_hex(va_arg(tab->args, unsigned long));
	tab->t_len += write(1, "0x", 2);
	i = 0;
	while (hex[i])
	{
		write(1, &hex[i], 1);
	i++;
	}
	tab->t_len += i;
	free(hex);
}

void	ft_print_hex(t_print *tab, int upper)
{
	char	*hex;
	int		i;
	int		j;

	hex = ft_turn_hex(va_arg(tab->args, unsigned int));
	if (upper > 0)
	{
		j = 0;
		while (hex[j] != '\0')
		{
			hex[j] = ft_toupper(hex[j]);
			j++;
		}
	}
	i = 0;
	while (hex[i])
	{
		write(1, &hex[i], 1);
	i++;
	}
	tab->t_len += i;
	free(hex);
}
