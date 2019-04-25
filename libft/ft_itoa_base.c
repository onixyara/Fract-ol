/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:48:09 by vonischu          #+#    #+#             */
/*   Updated: 2018/10/18 07:00:59 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		kostul(int *size, int *flag, int *tmp, int *value)
{
	*size = 0;
	*flag = 0;
	*tmp = *value;
}

char			*ft_itoa_base(int value, int base)
{
	char		*str;
	int			size;
	char		*tab;
	int			flag;
	int			tmp;

	kostul(&size, &flag, &tmp, &value);
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	str[0] = flag == 1 ? '-' : str[0];
	while (size > flag)
	{
		str[size-- - 1] = tab[ft_abs(value % base)];
		value /= base;
	}
	return (str);
}
