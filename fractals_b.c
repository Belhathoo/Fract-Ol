/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:02:38 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/26 01:02:40 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_tricorne(t_ptr *p, double col, double row)
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
		z.im = -1 * 2 * tmp * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_quadcorne(t_ptr *p, double col, double row)
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
		z.im = -3 * tmp * tmp * z.im + z.im * z.im * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_monsieur(t_ptr *p, double col, double row)
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
		if (z.re < 0)
			z.re *= -1;
		tmp = z.re;
		z.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re;
		z.im = -3 * tmp * tmp * z.im + z.im * z.im * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

char	*ft_detect_type(t_ptr *p)
{
	if (p->type == 0)
		return ("Mandelbrot");
	if (p->type == 1)
		return ("Julia");
	if (p->type == 2)
		return ("Tricorne");
	if (p->type == 3)
		return ("Monsieur");
	if (p->type == 4)
		return ("Quadcorne");
	if (p->type == 5)
		return ("Mandelbrot_1");
	return ("NO Fracts");
}
