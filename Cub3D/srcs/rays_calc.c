/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:44:15 by thomathi          #+#    #+#             */
/*   Updated: 2023/02/07 11:26:40 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

void	horizontal_calc(t_xu8t *xu8t, t_rays *r)
{
	reset_casting_values(r, 0);
	horizontal_casting(r);
	while (r->dof < 32)
	{
		r->mx = (int)(r->rx) >> 6;
		r->my = (int)(r->ry) >> 6;
		r->mp = r->my * xu8t->t_m->max_x + r->mx;
		horizontal_loop(r, xu8t);
	}
}

void	vertical_calc(t_xu8t *xu8t, t_rays *r)
{
	vertical_casting(r);
	reset_casting_values(r, 1);
	while (r->dof < 32)
	{
		r->mx = (int)(r->rx) >> 6;
		r->my = (int)(r->ry) >> 6;
		r->mp = r->my * xu8t->t_m->max_x + r->mx;
		vertical_loop(r, xu8t);
	}
}

void	select_ray(t_rays *r)
{
	if (r->dist_v < r->dist_h)
	{
		r->rx = r->vx;
		r->ry = r->vy;
		r->dist_t = r->dist_v;
		r->type = 'V';
	}
	else
	{
		r->rx = r->hx;
		r->ry = r->hy;
		r->dist_t = r->dist_h;
		r->type = 'H';
	}
}

double	dist(float x0, float y0, float x1, float y1)
{
	return (sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2)));
}
