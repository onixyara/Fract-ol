/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:09:35 by vonischu          #+#    #+#             */
/*   Updated: 2018/04/03 17:00:07 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strstr(const char *haystack, const char *needle)
{
	char				*p;
	size_t				len;
	int					i;

	len = ft_strlen(needle);
	if (len == 0)
		return ((char*)haystack);
	p = (char*)haystack;
	i = 0;
	while (p[i] != 0)
	{
		if (ft_memcmp((p + i), needle, len) == 0)
			return (p + i);
		i++;
	}
	return (NULL);
}
