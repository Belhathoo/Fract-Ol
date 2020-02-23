/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:04:55 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/26 01:04:56 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	ft_detect_move(t_ptr *p, int key)
{
	if (key == MLX_KEY_PAD_RIGHT)
	{
		p->x_min += 0.2 * p->speed;
		p->x_max += 0.2 * p->speed;
	}
	if (key == MLX_KEY_PAD_LEFT)
	{
		p->x_min -= 0.2 * p->speed;
		p->x_max -= 0.2 * p->speed;
	}
	if (key == MLX_KEY_PAD_UP)
	{
		p->y_min -= 0.2 * p->speed;
		p->y_max -= 0.2 * p->speed;
	}
	if (key == MLX_KEY_PAD_DOWN)
	{
		p->y_min += 0.2 * p->speed;
		p->y_max += 0.2 * p->speed;
	}
}

void	ft_detect_events(t_ptr *p, int key)
{
	if (key == MLX_KEY_PAD_P)
		p->pause = (p->pause + 1) % 2;
	if (key == MLX_KEY_PAD_T)
	{
		ft_reinitialise(p);
		p->type = (p->type + 1) % 6;
	}
	if (key == MLX_KEY_PAD_C)
		p->col_type = (p->col_type + 1) % 5;
	if (key == MLX_KEY_PAD_R)
		ft_reinitialise(p);
	if (key == MLX_KEY_PAD_W)
		p->prof_max++;
	if (key == MLX_KEY_PAD_S)
		p->prof_max--;
}

int		ft_deal_key(int key, t_ptr *p)
{
	if (key == MLX_KEY_PAD_ESC)
	{
		mlx_destroy_image(p->mlx, p->img);
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	if (key == MLX_KEY_PAD_PLUS)
	{
		ft_zoom(p, IMG_DIM / 2.0, IMG_DIM / 2.0, 0.8);
		p->speed *= 0.8;
	}
	if (key == MLX_KEY_PAD_MINUS)
	{
		ft_zoom(p, IMG_DIM / 2.0, IMG_DIM / 2.0, 1.0 / 0.8);
		p->speed *= 1.0 / 0.8;
	}
	ft_detect_events(p, key);
	ft_detect_move(p, key);
	ft_draw(p);
	return (key);
}

int		ft_mouse_move(int x, int y, t_ptr *p)
{
	if (p->pause == 0 && p->type == 1)
	{
		p->jul_re = (0.9 * x - IMG_DIM / 2) / IMG_DIM;
		p->jul_im = (0.9 * y - IMG_DIM / 2) / IMG_DIM;
	}
	ft_draw(p);
	return (0);
}

int		ft_mouse_press(int button, int x, int y, t_ptr *p)
{
	if (button == 5)
	{
		ft_zoom(p, x, y, 0.8);
		p->speed *= 0.8;
	}
	else if (button == 4)
	{
		ft_zoom(p, x, y, 1.0 / 0.8);
		p->speed *= 1.0 / 0.8;
	}
	ft_draw(p);
	return (button);
}
