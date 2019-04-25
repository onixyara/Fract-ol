/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:54:51 by vonischu          #+#    #+#             */
/*   Updated: 2018/10/21 20:26:15 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/fractol.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libmlx/mlx.h"

static void			calculate_fractal(t_fractal *fractal, t_complex c)
{
	if (fractal->type == 0)
		julia(fractal, c);
	if (fractal->type == 1)
		mandelbrot(fractal, c);
	if (fractal->type == 2)
		burningship(fractal, c);
}

static void			*draw_fractal(void *fractal)
{
	int				y;
	t_complex		c;
	int				l;
	t_fractal		*fract_ptr;

	l = SCREEN_WIDTH < SCREEN_HEIGHT ? SCREEN_WIDTH : SCREEN_HEIGHT;
	fract_ptr = (t_fractal*)fractal;
	fract_ptr->x = -1;
	y = fract_ptr->y;
	while (++(fract_ptr->x) < SCREEN_WIDTH)
	{
		fract_ptr->y = y;
		while (fract_ptr->y < fract_ptr->max_y)
		{
			c.r = 4 * (fract_ptr->x + fract_ptr->offset_x - SCREEN_WIDTH / 2.0)
														/ (l * fract_ptr->zoom);
			c.i = 4 * (fract_ptr->y + fract_ptr->offset_y - SCREEN_HEIGHT / 2.0)
														/ (l * fract_ptr->zoom);
			calculate_fractal(fract_ptr, c);
			fract_ptr->y++;
		}
	}
	return (fractal);
}

void				threads(t_fractal *fractal)
{
	t_fractal		*storage;
	pthread_t		*threads;
	int				j;

	storage = (t_fractal *)malloc(sizeof(t_fractal) * THREADS);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * THREADS);
	j = 0;
	while (j < THREADS)
	{
		ft_memcpy((void*)&storage[j], (void*)fractal, sizeof(t_fractal));
		storage[j].y = P_THR_STEP * j;
		storage[j].max_y = P_THR_STEP * (j + 1);
		j++;
	}
	j = 0;
	while (++j <= THREADS)
		pthread_create(&threads[j - 1], NULL, draw_fractal, &storage[j - 1]);
	while (j--)
		pthread_join(threads[j], NULL);
	free(storage);
	free(threads);
	mlx_put_image_to_window(fractal->mlx, fractal->win,
							fractal->img.img_ptr, 0, 0);
}
