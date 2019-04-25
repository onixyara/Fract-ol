/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:56:06 by vonischu          #+#    #+#             */
/*   Updated: 2018/10/21 19:58:52 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SCREEN_HEIGHT 600
# define SCREEN_WIDTH 800
# define THREADS 8
# define P_THR_STEP (SCREEN_WIDTH/THREADS)

typedef struct	s_complex
{
	double r;
	double i;
}				t_complex;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_fractal
{
	void			*mlx;
	void			*win;
	int				type;
	t_complex		c;
	int				iter;
	double			zoom;
	int				(*color)(int);
	int				x;
	int				y;
	int				max_y;
	t_img			img;
	int				last_x;
	int				last_y;
	double			offset_x;
	double			offset_y;
	int				tmp_x;
	int				tmp_y;
}					t_fractal;

int					mouse_move(int x, int y, t_fractal *fractal);
int					mouse_scroll(int b, int x, int y, t_fractal *fractal);
int					key_hook(int key, t_fractal *fractal);
int					close_window(t_fractal *fractal);
void				mandelbrot(t_fractal *fractal, t_complex c);
void				burningship(t_fractal *fractal, t_complex c);
void				julia(t_fractal *fractal, t_complex c);
int					color_2(int i);
int					color_1(int i);
void				threads(t_fractal *fractal);

#endif
