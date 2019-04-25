/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:30:25 by vonischu          #+#    #+#             */
/*   Updated: 2018/04/04 13:34:50 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnumeric(char *str)
{
	size_t	tmp;

	tmp = 0;
	while ((int)str[tmp])
	{
		if (!ft_isdigit(str[tmp]))
			return (0);
		tmp++;
	}
	return (1);
}
