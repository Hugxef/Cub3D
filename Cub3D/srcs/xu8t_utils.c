/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xu8t_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:47:37 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/15 15:39:01 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"
#include <stdio.h>

void	put_pixel(t_xu8t *xu8t, int x, int y, int c)
{
	char	*addr;

	if ((x >= 0 && x < xu8t->res_x) && (y >= 0 && y < xu8t->res_y))
	{
		xu8t->data = mlx_get_data_addr(xu8t->img \
				, &xu8t->bpp, &xu8t->size_l, &xu8t->endian);
		addr = xu8t->data + (y * xu8t->size_l + x * (xu8t->bpp / 8));
		*(unsigned int *)addr = c;
	}
}

void	dv6ted4(t_xu8t *xu8t, t_bres *s, t_rays *r, t_draw *d)
{
	unsigned int	c;
	int				inf_loop;

	d->i = 0;
	inf_loop = 0;
	while (d->i < s->dx_x && inf_loop < 500)
	{
		c = select_texture(xu8t, r, d);
		c = shadow_maker(c, d->l_height, xu8t->res_y);
		put_pixel(xu8t, d->i0[0], d->i0[1], c);
		d->i++;
		d->i0[0] += s->x_inc;
		s->ex -= s->dy;
		if (s->ex < 0)
		{
			d->i0[1] += s->y_inc + 1;
			s->ex += s->dx + 1;
		}
		inf_loop++;
	}
}

void	ep6dts(t_xu8t *xu8t, t_bres *s, t_rays *r, t_draw *d)
{
	unsigned int	c;
	int				inf_loop;

	d->i = 0;
	inf_loop = 0;
	while (d->i < s->dy_x && inf_loop < 500)
	{
		c = select_texture(xu8t, r, d);
		c = shadow_maker(c, d->l_height, xu8t->res_y);
		put_pixel(xu8t, d->i0[0], d->i0[1], c);
		d->i++;
		d->i0[1] += s->y_inc;
		s->ey -= s->dx;
		if (s->ey < 0)
		{
			d->i0[0] += s->x_inc + 1;
			s->ey += s->dy + 1;
		}
		inf_loop++;
	}
}

void	xu8t_draw_line(t_xu8t *xu8t, t_rays *r, t_draw *d)
{
	t_bres	*s;

	s = (t_bres *)malloc(sizeof(t_bres));
	s->ex = abs(d->i1[0] - d->i0[0]);
	s->ey = abs(d->i1[1] - d->i0[1]);
	s->dx = 2 * s->ex;
	s->dy = 2 * s->ey;
	s->dx_x = s->ex;
	s->dy_x = s->ey;
	s->x_inc = 1;
	s->y_inc = 1;
	if (d->i0[0] > d->i1[0])
		s->x_inc = -1;
	if (d->i0[1] > d->i1[1])
		s->y_inc = -1;
	if (s->dx_x > s->dy_x)
		dv6ted4(xu8t, s, r, d);
	if (s->dx_x < s->dy_x)
		ep6dts(xu8t, s, r, d);
	free(s);
}
