/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:03:12 by vonischu          #+#    #+#             */
/*   Updated: 2018/04/03 15:10:55 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dup;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	dup = ft_strdup(s);
	if (!dup)
		return (NULL);
	while (dup[i])
	{
		dup[i] = f(dup[i]);
		i++;
	}
	return (dup);
}
