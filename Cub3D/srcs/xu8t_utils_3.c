/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xu8t_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:02:52 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/14 13:30:40 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

unsigned int	jenny_color(int x, int y, t_xpm *texture, int l_h)
{
	char	*pixel;
	int		t_height;
	int		xx;
	int		yx;

	t_height = texture->x_height;
	if (l_h <= 0)
		l_h = 1;
	y = y * t_height / l_h;
	xx = y * (int)(texture->bpp / 8);
	yx = x * texture->size_l;
	xx += yx;
	pixel = texture->data + xx;
	return (*(unsigned int *) pixel);
}

void	xu8t_ceiling(t_xu8t *xu8t)
{
	int				y;
	int				x;
	int				shadow;
	unsigned int	color;

	y = 0;
	shadow = 0;
	while (y < xu8t->res_y / 2)
	{
		x = 0;
		while (x < xu8t->res_x)
		{
			color = create_rgb(xu8t->t_m->c_r,
					xu8t->t_m->c_g, xu8t->t_m->c_b, shadow);
			put_pixel(xu8t, x, y, color);
			x++;
		}
		y++;
		if (shadow != 255)
			shadow += 1;
	}
}

void	xu8t_floor(t_xu8t *xu8t)
{
	int				y;
	int				x;
	int				shadow;
	unsigned int	color;

	y = xu8t->res_y / 2;
	shadow = 255;
	while (y < xu8t->res_y)
	{
		x = 0;
		while (x < xu8t->res_x)
		{
			color = create_rgb(xu8t->t_m->f_r,
					xu8t->t_m->f_g, xu8t->t_m->f_b, shadow);
			put_pixel(xu8t, x, y, color);
			x++;
		}
		y++;
		if (shadow != 0)
			shadow -= 1;
	}
}
