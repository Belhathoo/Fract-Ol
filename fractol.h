/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:02:57 by belhatho          #+#    #+#             */
/*   Updated: 2020/01/26 01:03:08 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>

# define MLX_KEY_PAD_MINUS 78
# define MLX_KEY_PAD_PLUS 69
# define MLX_KEY_PAD_LEFT 123
# define MLX_KEY_PAD_RIGHT 124
# define MLX_KEY_PAD_UP 126
# define MLX_KEY_PAD_DOWN 125
# define MLX_KEY_PAD_P 35
# define MLX_KEY_PAD_T 17
# define MLX_KEY_PAD_W 13
# define MLX_KEY_PAD_Z 6
# define MLX_KEY_PAD_C 8
# define MLX_KEY_PAD_R 15
# define MLX_KEY_PAD_W 13
# define MLX_KEY_PAD_S 1
# define MLX_KEY_PAD_ESC 53

# define IMG_DIM 700
# define MAX_ITER 30

typedef struct		s_ptr
{
	void			*win;
	void			*mlx;
	void			*img;
	int				*data;
	int				bpp;
	int				size;
	int				endian;
	double			x_max;
	double			x_min;
	double			y_max;
	double			y_min;
	double			zoom;
	double			jul_re;
	double			jul_im;
	int				type;
	double			speed;
	int				pause;
	int				prof_max;
	int				col_type;
}					t_ptr;

typedef struct		s_com
{
	double			im;
	double			re;
}					t_com;

int					ft_get_color(int iter, t_ptr *p);
void				ft_draw_fractal(t_ptr *p, int b, int a);
void				ft_write_img(t_ptr *p);
void				ft_reinitialise(t_ptr *p);
char				*ft_detect_type(t_ptr *p);
void				ft_draw(t_ptr *p);
void				ft_zoom(t_ptr *p, double x, double y, double k);
void				ft_initial(t_ptr *p);
void				ft_detect_fract(t_ptr *p, char **argv);
void				ft_detect_move(t_ptr *p, int key);
void				ft_detect_events(t_ptr *p, int key);
int					ft_deal_key(int key, t_ptr *p);
int					ft_mouse_move(int x, int y, t_ptr *p);
int					ft_mouse_press(int button, int x, int y, t_ptr *p);
void				ft_mlx_putpixel(t_ptr *p, int x, int y, int color);
void				ft_creat_window(t_ptr *p);
void				ft_creat_image(t_ptr *p);
int					ft_fin(t_ptr *p);
int					ft_color_bw(int iter, t_ptr *p);
int					ft_color_marron(int iter, t_ptr *p);
int					ft_color_yellow(int iter, t_ptr *p);
int					ft_color_green(int iter, t_ptr *p);
int					ft_color0(int iter, t_ptr *p);
int					ft_tricorne(t_ptr *p, double col, double row);
int					ft_quadcorne(t_ptr *p, double col, double row);
int					ft_monsieur(t_ptr *p, double col, double row);
int					ft_julia(t_ptr *p, double col, double row);
int					ft_mandelbrot(t_ptr *p, double col, double row);
int					ft_mandelbrot_1(t_ptr *p, double col, double row);

#endif
