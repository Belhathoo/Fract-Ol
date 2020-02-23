/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:39:44 by belhatho          #+#    #+#             */
/*   Updated: 2020/02/23 21:39:47 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_putpixel(t_ptr *p, int x, int y, int color)
{
	if (x >= 0 && x < IMG_DIM && y >= 0 && y < IMG_DIM)
		p->data[y * (int)IMG_DIM + x] = color;
}

void	ft_creat_window(t_ptr *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, IMG_DIM, IMG_DIM + 100, "Fractol");
}

void	ft_creat_image(t_ptr *p)
{
	p->img = mlx_new_image(p->mlx, IMG_DIM, IMG_DIM);
	p->data = (int*)mlx_get_data_addr(p->img, &p->bpp, &p->size, &p->endian);
}

void	ft_reinitialise(t_ptr *p)
{
	p->speed = 0.8;
	p->prof_max = MAX_ITER;
	p->y_max = 2.0;
	p->x_max = 2.0;
	p->x_min = -2.0;
	p->y_min = -2.0;
}

int		ft_fin(t_ptr *p)
{
	mlx_destroy_image(p->mlx, p->img);
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
	return (1);
}
