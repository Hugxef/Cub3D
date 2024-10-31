/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xu8t.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:34:57 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/15 15:37:50 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

unsigned int	select_texture(t_xu8t *xu8t, t_rays *r, t_draw *d)
{
	unsigned int	color;
	int				x;
	int				y;

	x = d->i0[0];
	y = d->i;
	if (r->type == 'V')
	{
		x = ((int)r->ry / 64 - r->ry / 64) * 64;
		if (r->ra <= xu8t->npi && r->ra >= xu8t->spi)
			color = jenny_color(x, y, xu8t->nx, d->l_height);
		else
			color = jenny_color(x, y, xu8t->wx, d->l_height);
	}
	else if (r->type == 'H')
	{
		x = ((int)r->rx / 64 - r->rx / 64) * 64;
		if (r->ra >= xu8t->wpi && r->ra <= xu8t->epi)
			color = jenny_color(x, y, xu8t->sx, d->l_height);
		else
			color = jenny_color(x, y, xu8t->ex, d->l_height);
	}
	else
		color = create_rgb(255, 255, 255, 0);
	return (color);
}

unsigned int	shadow_maker(unsigned int color, float l_h, float res)
{
	int	shadow;

	shadow = l_h / res * 255;
	if (shadow > 255)
		shadow = 255;
	color -= ((shadow & 0xff) << 24);
	return (color);
}

void	xu8t_draw(t_xu8t *xu8t, t_rays *r, int x)
{
	t_draw	*d;

	d = malloc(sizeof(t_draw));
	d->ca = calc_ca(xu8t, r);
	r->dist_t = r->dist_t * cos(d->ca);
	d->l_height = (xu8t->t_m->tile * xu8t->res_y) / r->dist_t;
	d->l_offset = (xu8t->res_y / 2) - (d->l_height / 2);
	d->i = 0;
	d->i0[1] = d->l_offset;
	d->i1[1] = d->l_offset + d->l_height;
	while (d->i < r->loop_offset)
	{
		d->i0[0] = (x * r->loop_offset) + d->i;
		d->i1[0] = (x * r->loop_offset) + d->i;
		xu8t_draw_line(xu8t, r, d);
		d->i++;
	}
}

void	xu8t_make(t_xu8t *xu8t)
{
	t_rays	*r;
	int		i;

	xu8t_ceiling(xu8t);
	xu8t_floor(xu8t);
	r = malloc(sizeof(t_rays));
	i = 0;
	rays_init(xu8t, r);
	rays_angle_calc(r, xu8t->t_p->angle, 0);
	while (i < r->fov * r->rays_coef)
	{
		horizontal_calc(xu8t, r);
		vertical_calc(xu8t, r);
		select_ray(r);
		r->i0[0] = r->px;
		r->i0[1] = r->py;
		r->i1[0] = r->rx;
		r->i1[1] = r->ry;
		xu8t_draw(xu8t, r, i);
		i++;
		rays_angle_calc(r, xu8t->t_p->angle, i);
	}
	free(r->i0);
	free(r->i1);
	free(r);
}

void	xu8t_render(t_xu8t *xu8t)
{
	xu8t->img = mlx_new_image(xu8t->mlx, xu8t->res_x, xu8t->res_y);
	xu8t_make(xu8t);
	mlx_put_image_to_window(xu8t->mlx, xu8t->win, xu8t->img, 0, 0);
}
