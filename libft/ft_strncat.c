/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:18:05 by vonischu          #+#    #+#             */
/*   Updated: 2018/04/03 17:24:26 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned			len1;
	unsigned			len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ft_strncpy(&s1[len1], s2, ((len2 < n) ? len2 : n));
	s1[len1 + ((len2 < n) ? len2 : n)] = 0;
	return (s1);
}
