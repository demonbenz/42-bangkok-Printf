/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:54:18 by otangkab          #+#    #+#             */
/*   Updated: 2022/09/20 15:16:41 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<limits.h>
#include "ft_printf.h"
#include "libft.h"

static int	ft_digit(unsigned int n)
{
	int	d;

	if (n == 0)
		return (1);
	d = 0;
	while (n)
	{
		n = n / 10;
		d++;
	}
	return (d);
}

char	*ft_unsitoa(unsigned int n)
{
	int		digit;
	char	*tmp;

	digit = ft_digit(n);
	tmp = (char *)malloc(sizeof(char) * (digit + 1));
	if (!tmp)
		return (0);
	tmp[digit] = '\0';
	while (digit-- > 0)
	{
		tmp[digit] = (n % 10) + '0';
		n = n / 10;
	}
	return (tmp);
}

void	ft_print_perc(t_print *tab)
{
	write(1, "%", 1);
	tab->t_len ++;
}

/*
char	*ft_prefix(char *str)
{
	char	*ox;
	char	*tmp;

	ox = "0x";
	tmp = ft_calloc(sizeof(char), ft_strlen(str) + 3);
	if (!tmp)
		return (NULL);
	tmp = ft_strjoin(ox, str);
	return (tmp);
}

char	*ft_unsitoa(unsigned int n)
{
	int		digit;
	char	*tmp;
	unsigned long						long_n;

	long_n = n;
	digit = ft_digit(long_n);
	tmp = (char *)malloc(sizeof(char) * (digit + 1));
	if (!tmp)
		return (0);
	tmp[digit] = '\0';
	while (digit-- > 0)
	{
		tmp[digit] = (long_n % 10) + '0';
		long_n = long_n / 10;
	}
	return (tmp);
}

int	main(void)
{
	int	maxnum;
	int	minnum;
	int	n;
	unsigned int n2, n3;
	char	*ret;

	maxnum = 2147483647;
	minnum = -2147483648;
	n = -623;
	n2 = UINT_MAX;
	n3 = 4294967295;
	ret = ft_unsitoa(n2);

	printf("ret = %s", ret);
	free(ret);
}*/
