/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:57:44 by atardif           #+#    #+#             */
/*   Updated: 2023/01/16 13:22:22 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	isometric(float *x, float *y, int z)
{
	float	xtemp;
	float	ytemp;

	xtemp = *x;
	ytemp = *y;
	*x = (xtemp - ytemp) * cos(0.6);
	*y = ((xtemp + ytemp) * sin(0.6) - z);
}


void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + ((y * img->line_len) + (x * (img->bpp / 8)));
	*(int *)pixel = color;
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			img_pix_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_line(float x, float y, float x1, float y1, t_data *data)
{
	float	xincr;
	float	yincr;
	float	err;
	int	zoom;
	int	z;
	int	z1;

	z = data->tab[(int)y][(int)x];
	z1 = data->tab[(int)y1][(int)x1];
	//z /= 100;
	//z1 /= 100;
	if (z > 0 || z1 > 0)
		data->color = 0x0000FF00;
	else if (z < 0 || z1 < 0)
		data->color = 0x00FF0000;
	else
		data->color = 0x00FFFFFF;
	/*isometric(&x, &y, z);
	isometric(&x1, &y1, z1);*/
	zoom = 20;
	x *= zoom;
	y *= zoom;
	x1 *= zoom;
	y1 *= zoom;
	x += 250;
	y += 250;
	x1 += 250;
	y1 += 250;
	xincr = x1 - x;
	yincr = y1 - y;
	err = find_max(find_abs(xincr), find_abs(yincr));
	xincr /= err;
	yincr /= err;
	while((int)x < (int)x1 || (int)y < (int)y1)
	{
		img_pix_put(&data->img, x, y, data->color);
		x += xincr;
		y += yincr;
	}

}


void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x + 1 < data->width)
				draw_line(x, y, x + 1, y, data);
			if (y + 1 < data->height)
				draw_line(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
