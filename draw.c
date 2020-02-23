/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:02:16 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/26 01:02:18 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_mlx_string(t_ptr *p)
{
	mlx_string_put(p->mlx, p->win, 0, 0, 0x555555 \
			, "FRACTOL");
	mlx_string_put(p->mlx, p->win, 340, 0, 0x111111, "1337");
	mlx_string_put(p->mlx, p->win, 610, 0, 0x555555, "BELHATHO");
	mlx_string_put(p->mlx, p->win, 0, 730, 0x1B4F72
	, "  TYPES              COLORS               \
		ZOOM           	  	  	MOVE");
	mlx_string_put(p->mlx, p->win, 0, 745, 0x2874A6\
		, "   'T'                 'C'           \
		'+' '-' (Mouse) 	      (Arrows)");
	mlx_string_put(p->mlx, p->win, 0, 775, 0x212F3D
			, " RESET 'R'             Pause (JULIA) 'P'       \
			ITERATION  'W'/'S' :");
	mlx_string_put(p->mlx, p->win, 670, 775, 0xFF0000,
			ft_itoa(p->prof_max));
	mlx_string_put(p->mlx, p->win, 280, 700, 0x555555\
					, "Fractal: ");
	mlx_string_put(p->mlx, p->win, 370, 700, 0xFF0000, ft_detect_type(p));
}

void		side_win(t_ptr *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < IMG_DIM)
	{
		j = IMG_DIM + 5;
		while (j < IMG_DIM + 100)
		{
			mlx_pixel_put(p->mlx, p->win, i, j, 0xD5D8DC);
			j++;
		}
		i++;
	}
	ft_mlx_string(p);
}

void		ft_draw_fractal(t_ptr *p, int b, int a)
{
	if (p->type == 0)
		ft_mlx_putpixel(p, b, a, ft_mandelbrot(p, b, a));
	else if (p->type == 1)
		ft_mlx_putpixel(p, b, a, ft_julia(p, b, a));
	else if (p->type == 2)
		ft_mlx_putpixel(p, b, a, ft_tricorne(p, b, a));
	else if (p->type == 3)
		ft_mlx_putpixel(p, b, a, ft_monsieur(p, b, a));
	else if (p->type == 4)
		ft_mlx_putpixel(p, b, a, ft_quadcorne(p, b, a));
	else if (p->type == 5)
		ft_mlx_putpixel(p, b, a, ft_mandelbrot_1(p, b, a));
}

void		ft_write_img(t_ptr *p)
{
	int			a;
	int			b;

	a = 0;
	while (a < IMG_DIM)
	{
		b = 0;
		while (b < IMG_DIM)
		{
			ft_draw_fractal(p, b, a);
			b++;
		}
		a++;
	}
}

void		ft_draw(t_ptr *p)
{
	ft_bzero(p->data, (int)IMG_DIM * (int)IMG_DIM * 4);
	ft_write_img(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	side_win(p);
}
