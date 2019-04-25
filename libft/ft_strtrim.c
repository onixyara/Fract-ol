/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 21:58:39 by vonischu          #+#    #+#             */
/*   Updated: 2018/04/03 18:04:15 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	d;
	size_t	f;

	if (!s)
		return (NULL);
	d = 0;
	while (s[d] == ' ' || s[d] == '\t' || s[d] == '\n')
		d++;
	if (s[d] == '\0')
		return (ft_strnew(0));
	f = ft_strlen(s) - 1;
	while (s[f] == ' ' || s[f] == '\t' || s[f] == '\n')
		f--;
	return (ft_strsub(s, d, f - d + 1));
}
