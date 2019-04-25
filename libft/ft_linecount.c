/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linecount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 06:57:08 by vonischu          #+#    #+#             */
/*   Updated: 2018/10/19 19:49:44 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static int			ft_1stwordcount(char c)
{
	static int		ret = 0;
	static int		flag = 0;

	if (c == ' ' || c == '\t')
		flag = 0;
	else if (flag == 0 && (c != ' ') && (c != '\t'))
	{
		flag = 1;
		ret++;
	}
	return (ret);
}

void				ft_valid(char c, int *fg2, t_doubleint **db)
{
	static int		fg1 = 0;

	if (c == '\n')
	{
		(*db)->a++;
		fg1 = 1;
		*fg2 = 1;
	}
	else
		*fg2 = 0;
	if (fg1 == 0)
	{
		(*db)->b = ft_1stwordcount(c);
	}
}

int					ft_linecount(char *file, t_doubleint *doubleint)
{
	int				fd;
	char			buf[1];
	int				flag2;

	flag2 = -1;
	fd = 0;
	if (!file || (fd = open(file, O_RDONLY)) == -1 || read(fd, buf, 0) != 0)
	{
		close(fd);
		return (0);
	}
	doubleint->a = 0;
	while (read(fd, buf, 1))
	{
		ft_valid(buf[0], &flag2, &doubleint);
	}
	if (flag2 == 0)
		doubleint->a++;
	doubleint->a = doubleint->a == 0 ? 1 : doubleint->a;
	close(fd);
	return (1);
}
