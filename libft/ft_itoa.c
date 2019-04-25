/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:18:57 by vonischu          #+#    #+#             */
/*   Updated: 2018/04/04 13:20:25 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(int n)
{
	int			len;

	len = 1;
	if (n < 0)
		len++;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			len;

	len = ft_intlen(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	else
		n = 0 - n;
	while (n / 10)
	{
		str[--len] = (0 - (n % 10)) + '0';
		n /= 10;
	}
	str[--len] = (0 - (n % 10)) + '0';
	return (str);
}
