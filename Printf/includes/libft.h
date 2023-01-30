/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:33:30 by otangkab          #+#    #+#             */
/*   Updated: 2022/09/10 23:53:11 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define LLONG_MAX 9223372036854775807
# include<stdlib.h>
# include<stddef.h>
# include<unistd.h>

void	ft_bzero(void *str, size_t num);
void	*ft_calloc(size_t num, size_t size);
size_t	ft_strlen(const char *s);
int		ft_toupper(int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);

#endif
