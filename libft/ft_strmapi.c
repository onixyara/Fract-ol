/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:16:17 by vonischu          #+#    #+#             */
/*   Updated: 2018/06/25 13:28:00 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s,
			char (*f)(unsigned int, char))
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
		dup[i] = f(i, dup[i]);
		i++;
	}
	return (dup);
}
