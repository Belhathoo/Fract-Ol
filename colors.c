/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:01:48 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/26 01:01:51 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_color_bw(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x000000);
	if (iter % 2 == 0)
		return (0x000000);
	return (0xFFFFFF);
}

int		ft_color_marron(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0xB71C1C);
	return ((int)(0x4E342E * iter > 0xFFFFFF ? (int)(0x4FC3F7 / iter) :
				0x4E342E * iter));
}

int		ft_color_yellow(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x000000);
	return (0xFFD700 + iter * 550);
}

int		ft_color_green(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x000000);
	return ((int)(0x28B463 * iter > 0xFFFFFF ? 0x28B463 / iter / 4 :
				0x28B463 * iter));
}

int		ft_color0(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x000000);
	return ((int)(0xC34863 - iter * 10));
}
