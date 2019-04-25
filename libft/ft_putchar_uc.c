/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_uc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 12:40:38 by vonischu          #+#    #+#             */
/*   Updated: 2018/04/17 10:34:30 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printchar(int n, int len, char *str)
{
	int			i;

	i = 0;
	if (len == 1)
		str[0] = (n & 127);
	if (len == 2)
	{
		str[1] = ((n & 63) | 128);
		str[0] = (((n >> 6) & 31) | 192);
	}
	if (len == 3)
	{
		str[2] = ((n & 63) | 128);
		str[1] = (((n >> 6) & 63) | 128);
		str[0] = (((n >> 12) & 15) | 224);
	}
	if (len == 4)
	{
		str[3] = ((n & 63) | 128);
		str[2] = (((n >> 6) & 63) | 128);
		str[1] = (((n >> 12) & 63) | 128);
		str[0] = (((n >> 18) & 7) | 240);
	}
	while (i < len)
		write(1, &(str[i++]), 1);
}

void			ft_putchar_uc(int n)
{
	int			len;
	char		*str;

	if (n <= 127)
		len = 1;
	if ((n > 127) && (n <= 2047))
		len = 2;
	if ((n > 2047) && (n <= 65536))
		len = 3;
	if ((n > 65536) && (n <= 2097151))
		len = 4;
	str = (char *)malloc(len);
	ft_printchar(n, len, str);
	while (!str)
		free(str++);
}
