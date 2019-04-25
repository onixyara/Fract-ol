/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:55:35 by vonischu          #+#    #+#             */
/*   Updated: 2018/10/21 20:26:15 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <math.h>

static t_complex		add_complex(t_complex a, t_complex b)
{
	t_complex c;

	c.r = a.r + b.r;
	c.i = a.i + b.i;
	return (c);
}

static t_complex		sqr_complex(t_complex a)
{
	t_complex c;

	c.r = a.r * a.r - a.i * a.i;
	c.i = 2 * a.r * a.i;
	return (c);
}

void					mandelbrot(t_fractal *fractal, t_complex c)
{
	int					i;
	t_complex			z0;
	t_complex			tmp;

	i = 0;
	z0.r = c.r;
	z0.i = c.i;
	while (z0.r * z0.r + z0.i * z0.i <= 4 && ++i <= fractal->iter)
	{
		tmp.r = z0.r * z0.r - z0.i * z0.i;
		tmp.i = 2 * z0.r * z0.i;
		z0.r = tmp.r + c.r;
		z0.i = tmp.i + c.i;
	}
	if (i > fractal->iter)
		fractal->img.data[fractal->y * SCREEN_WIDTH + fractal->x] = 0;
	else
		fractal->img.data[fractal->y * SCREEN_WIDTH + fractal->x] =
											i + fractal->color(i);
}

void					burningship(t_fractal *fractal, t_complex c)
{
	int					i;
	t_complex			z;
	double				tmp;

	i = 1;
	z.r = c.r;
	z.i = c.i;
	while (z.r * z.r + z.i * z.i <= 4 && i <= fractal->iter)
	{
		tmp = z.r * z.r - z.i * z.i + c.r;
		z.i = fabs(2 * z.r * z.i) + c.i;
		z.r = fabs(tmp);
		i++;
	}
	if (i > fractal->iter)
		fractal->img.data[fractal->y * SCREEN_WIDTH + fractal->x] = 0;
	else
		fractal->img.data[fractal->y * SCREEN_WIDTH + fractal->x] =
											i + fractal->color(i);
}

void					julia(t_fractal *fractal, t_complex c)
{
	int					i;
	t_complex			z;

	i = 0;
	z = add_complex(sqr_complex(c), fractal->c);
	while ((z.r * z.r + z.i * z.i) < 4 && ++i <= fractal->iter)
	{
		z = add_complex(sqr_complex(z), fractal->c);
	}
	if (i > fractal->iter)
		fractal->img.data[fractal->y * SCREEN_WIDTH + fractal->x] = 0;
	else
		fractal->img.data[fractal->y * SCREEN_WIDTH + fractal->x] =
												fractal->color(i);
}
