/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:46:16 by otangkab          #+#    #+#             */
/*   Updated: 2022/06/28 20:16:47 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
#include"libft.h"

int	ft_digit(int n)
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

char	*ft_itoa(int n)
{
	int		digit;
	char	*tmp;
	char	sign;
	long	long_n;

	long_n = n;
	digit = ft_digit(long_n);
	if (n < 0)
	{
		sign = '-';
		long_n = long_n * -1;
		digit++;
	}
	tmp = (char *)malloc(sizeof(char) * (digit + 1));
	if (!tmp)
		return (0);
	tmp[digit] = '\0';
	while (digit-- > 0)
	{
		tmp[digit] = (long_n % 10) + '0';
		long_n = long_n / 10;
	}
	if (n < 0)
		tmp[0] = sign;
	return (tmp);
}
/*
int	main(void)
{
	int	maxnum;
	int	minnum;
	int	n;
	char	*ret;

	maxnum = 2147483647;
	minnum = -2147483648;
	n = -623;
	ret = ft_itoa(n);
	printf("ret = %s", ret);
	free(ret);
}*/
