/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:55:45 by vonischu          #+#    #+#             */
/*   Updated: 2018/10/21 20:26:44 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../libmlx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>

static void			select_type(t_fractal *fractal, char *fractol)
{
	if (!ft_strcmp(fractol, "julia"))
		fractal->type = 0;
	else if (!ft_strcmp(fractol, "mandelbrot"))
		fractal->type = 1;
	else if (!ft_strcmp(fractol, "burningship"))
		fractal->type = 2;
}

static t_fractal	*mall_check(t_fractal *fractal, char *fractol)
{
	if (!(fractal = malloc(sizeof(t_fractal))))
		return (NULL);
	if (!(fractal->mlx = mlx_init()))
		return (NULL);
	if (!(fractal->win = mlx_new_window(fractal->mlx, SCREEN_WIDTH,
											SCREEN_HEIGHT, fractol)))
		return (NULL);
	if (!(fractal->img.img_ptr = mlx_new_image(fractal->mlx, SCREEN_WIDTH,
														SCREEN_HEIGHT)))
		return (NULL);
	return (fractal);
}

static t_fractal	*init(char *fractol)
{
	t_fractal		*fractal;

	fractal = NULL;
	fractal = mall_check(fractal, fractol);
	fractal->img.data = (int *)mlx_get_data_addr(fractal->img.img_ptr,
		&fractal->img.bpp, &fractal->img.size_l, &fractal->img.endian);
	select_type(fractal, fractol);
	fractal->c.r = -0.7;
	fractal->c.i = 0.27015;
	fractal->iter = 50;
	fractal->zoom = 1;
	fractal->color = color_1;
	fractal->last_x = 0;
	fractal->last_y = 0;
	fractal->offset_y = 0;
	fractal->offset_x = 0;
	fractal->tmp_x = SCREEN_WIDTH / 2;
	fractal->tmp_y = 0;
	return (fractal);
}

static int			print_error(char *str)
{
	ft_putstr(str);
	return (0);
}

int					main(int argc, char **argv)
{
	t_fractal *fractal;

	if (argc != 2 || (ft_strcmp(argv[1], "julia") &&
	ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "burningship")))
		return (print_error("usage: fractol [julia/mandelbrot/burningship]\n"));
	if (!(fractal = init(argv[1])))
		return (print_error("error: fractal couldn't init"));
	threads(fractal);
	mlx_hook(fractal->win, 17, 1 << 17, &close_window, fractal);
	mlx_hook(fractal->win, 2, 5, key_hook, fractal);
	mlx_hook(fractal->win, 4, 0, mouse_scroll, fractal);
	mlx_hook(fractal->win, 6, 0, mouse_move, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
