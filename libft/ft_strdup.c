/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:54:11 by vonischu          #+#    #+#             */
/*   Updated: 2018/10/18 20:23:17 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char		*ft_strdup(const char *src)
{
	char				*dup;

	dup = ft_strnew(ft_slen(src));
	if (dup)
		dup = ft_strcpy(dup, src);
	return (dup);
}
