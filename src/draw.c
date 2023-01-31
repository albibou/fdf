/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:57:44 by atardif           #+#    #+#             */
/*   Updated: 2023/01/31 15:45:54 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + ((y * img->line_len) + (x * (img->bpp / 8)));
	*(int *)pixel = color;
}

void	render_background(t_img *img, t_data *data)
{
	int	i;
	int	j;
	int	color;

	if (data->palette == 2)
		color = 0x00FBFBFB;
	else
		color = 0x00171717;
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

void	draw_rectangle(t_img *img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 200)
	{
		j = 0;
		while (j <= 399)
		{
			img_pix_put(img, x + j, y + i, 0x00393E46);
			j++;
		}
		i++;
	}
}

static void	draw_line(t_points points, t_data *data)
{
	float	xincr;
	float	yincr;
	float	err;

	set_params(&points, data);
	xincr = points.x1 - points.x;
	yincr = points.y1 - points.y;
	err = ft_findmax(ft_findabs(xincr), ft_findabs(yincr));
	xincr /= err;
	yincr /= err;
	while ((int)(points.x1 - points.x) || (int)(points.y1 - points.y))
	{
		if (points.x < W_WIDTH && points.x >= 0 && points.y < W_HEIGHT
			&& points.y >= 0)
			img_pix_put(&data->img, points.x, points.y, data->color);
		points.x += xincr;
		points.y += yincr;
	}
}

void	draw_map(t_data *data, t_points points)
{
	points.y = 0;
	while (points.y < data->height)
	{
		points.x = 0;
		while (points.x < data->width)
		{
			if (points.x + 1 < data->width)
			{
				points.x1 = points.x + 1;
				points.y1 = points.y;
				draw_line(points, data);
			}
			if (points.y + 1 < data->height)
			{
				points.y1 = points.y + 1;
				points.x1 = points.x;
				draw_line(points, data);
			}
			points.x++;
		}
		points.y++;
	}
}
