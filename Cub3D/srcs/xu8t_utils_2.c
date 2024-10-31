/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xu8t_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:02:45 by thomathi          #+#    #+#             */
/*   Updated: 2022/11/18 11:02:46 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xu8t.h"

unsigned long	create_rgb(int r, int g, int b, int a)
{
	unsigned long	rgb;

	rgb = ((a & 0xff) << 24);
	rgb += ((r & 0xff) << 16);
	rgb += ((g & 0xff) << 8);
	rgb += (b & 0xff);
	return (rgb);
}

float	calc_ca(t_xu8t *xu8t, t_rays *r)
{
	float	ca;

	ca = xu8t->t_p->angle - r->ra;
	if (ca < 0)
		ca += 2 * M_PI;
	if (ca > 2 * M_PI)
		ca -= 2 * M_PI;
	return (ca);
}
