/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listeners.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:55:55 by vonischu          #+#    #+#             */
/*   Updated: 2018/10/21 20:27:32 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <libc.h>
#include "../libmlx/mlx.h"

int				close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal);
	exit(EXIT_SUCCESS);
}

int				key_hook(int key, t_fractal *fractal)
{
	if (key == 53)
		return (close_window(fractal));
	else if (key == 18 && fractal->iter > 1)
		fractal->iter--;
	else if (key == 19)
		fractal->iter++;
	else if (key == 123)
		fractal->offset_x += 20;
	else if (key == 124)
		fractal->offset_x -= 20;
	else if (key == 125)
		fractal->offset_y -= 20;
	else if (key == 126)
		fractal->offset_y += 20;
	else if (key == 21)
	{
		if (fractal->color == color_1)
			fractal->color = color_2;
		else
			fractal->color = color_1;
	}
	mlx_clear_window(fractal->mlx, fractal->win);
	threads(fractal);
	return (0);
}

int				mouse_scroll(int b, int x, int y, t_fractal *fractal)
{
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return (0);
	if ((b == 4 || b == 5) &&
		(x > 0 && x < SCREEN_WIDTH && y > 0 && y < SCREEN_HEIGHT))
	{
		if (b == 4)
			fractal->zoom *= 1.1;
		else
			fractal->zoom /= 1.1;
	}
	mlx_clear_window(fractal->mlx, fractal->win);
	threads(fractal);
	return (0);
}

int				mouse_move(int x, int y, t_fractal *fractal)
{
	if ((fractal->type == 0) && (fractal->c.r && fractal->c.i)
		&& (x > 0 && x < SCREEN_WIDTH && y > 0 && y < SCREEN_HEIGHT))
	{
		fractal->c.r += ((double)x - fractal->last_x) /
											(SCREEN_WIDTH * 2);
		fractal->c.i += ((double)y - fractal->last_y) /
											(SCREEN_HEIGHT * 2);
		fractal->last_x = x;
		fractal->last_y = y;
	}
	mlx_clear_window(fractal->mlx, fractal->win);
	threads(fractal);
	return (0);
}
