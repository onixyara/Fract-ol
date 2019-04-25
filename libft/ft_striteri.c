/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:36:40 by vonischu          #+#    #+#             */
/*   Updated: 2018/04/17 10:35:07 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (str && f)
		while (str[i])
		{
			f(i, (str + i));
			i++;
		}
}
