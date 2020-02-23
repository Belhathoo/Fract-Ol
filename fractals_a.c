/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:02:30 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/26 01:02:31 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_julia(t_ptr *p, double col, double row)
{
	int				iter;
	t_com			z;
	t_com			c;
	double			tmp;

	z.re = p->x_min + ((p->x_max - p->x_min) / IMG_DIM) * col;
	z.im = p->y_min + ((p->y_max - p->y_min) / IMG_DIM) * row;
	c.re = p->jul_re;
	c.im = p->jul_im;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < p->prof_max)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_mandelbrot(t_ptr *p, double col, double row)
{
	int				iter;
	t_com			z;
	t_com			c;
	double			tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / IMG_DIM) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / IMG_DIM) * row;
	z.re = 0.0;
	z.im = 0.0;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < p->prof_max)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_mandelbrot_1(t_ptr *p, double col, double row)
{
	int				iter;
	t_com			z;
	t_com			c;
	double			tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / IMG_DIM) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / IMG_DIM) * row;
	z.re = 0.0;
	z.im = 0.0;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < p->prof_max)
	{
		tmp = z.re;
		z.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re;
		z.im = 3 * tmp * tmp * z.im - z.im * z.im * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_get_color(int iter, t_ptr *p)
{
	if (p->col_type == 0)
		return (ft_color_bw(iter, p));
	if (p->col_type == 1)
		return (ft_color_yellow(iter, p));
	if (p->col_type == 2)
		return (ft_color_green(iter, p));
	if (p->col_type == 3)
		return (ft_color_marron(iter, p));
	return (ft_color0(iter, p));
}
