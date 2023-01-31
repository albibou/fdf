/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpoints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:20:37 by atardif           #+#    #+#             */
/*   Updated: 2023/01/31 17:35:53 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = ((*x + *y) * sin(0.8) - z);
}

static void	cabinet(float *x, float *y, int z)
{
	*x = *x + (z * cos(0.6)) / 2;
	*y = *y + (z * sin(0.6)) / 2;
}

void	set_params(t_points *points, t_data *data)
{
	points->z = data->tab[(int)points->y][(int)points->x];
	points->z1 = data->tab[(int)points->y1][(int)points->x1];
	data->color = color_hub(data, ft_findmax(points->z, points->z1));
	points->z /= data->zcoeff;
	points->z1 /= data->zcoeff;
	if (data->projection == 0)
	{
		isometric(&points->x, &points->y, points->z);
		isometric(&points->x1, &points->y1, points->z1);
	}
	else if (data->projection == 1)
	{
		cabinet(&points->x, &points->y, points->z);
		cabinet(&points->x1, &points->y1, points->z1);
	}
	points->x *= data->zoom;
	points->y *= data->zoom;
	points->x1 *= data->zoom;
	points->y1 *= data->zoom;
	points->x += data->xoffset;
	points->y += data->yoffset;
	points->x1 += data->xoffset;
	points->y1 += data->yoffset;
}
