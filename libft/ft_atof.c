/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 06:55:09 by vonischu          #+#    #+#             */
/*   Updated: 2018/10/21 19:26:39 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float				ft_atof(const char *str)
{
	float			f;
	int				p;

	f = ft_atoi(str);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	str = (*str == '-' || *str == '+') ? (str + 1) : (str);
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		p = 10;
		while (ft_isdigit(*str))
		{
			f = f + ((f < 0) ? (-1) : (1)) * ((float)(*str - '0') / (float)p);
			p *= 10;
			str++;
		}
	}
	return (f);
}
