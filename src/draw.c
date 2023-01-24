/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:57:44 by atardif           #+#    #+#             */
/*   Updated: 2023/01/24 18:34:43 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	isometric(float *x, float *y, int z)
{
	/*float	xtemp;
	float	ytemp;

	xtemp = *x;
	ytemp = *y;*/
	*x = (*x - *y) * cos(0.75);
	*y = ((*x + *y) * sin(0.75) - z);
}


void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + ((y * img->line_len) + (x * (img->bpp / 8)));
	*(int *)pixel = color;
}

void	render_background(t_img *img, t_data *data)
{
	int	i;
	int	j;
	int 	color;

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
		while(j <= 399)
		{
			img_pix_put(img, x + j, y + i, 0x00393E46);
			j++;
		}
		i++;
	}
}


void	render_instructionbox(t_img *img)
{
	draw_rectangle(img, 0, 56);
	draw_rectangle(img, 0, 312);
	draw_rectangle(img, 0, 568);
	draw_rectangle(img, 0, 824);
}

void	render_instructiontext(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 122, 0x00E5E7E6, "Move up / down  :  W / S");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 189, 0x00E5E7E6, "Move left / right  :  A / D");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 378, 0x00E5E7E6, "Zoom in / out  :  P / L");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 445, 0x00E5E7E6, "Decrease / increase height  :  N / M");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 634, 0x00E5E7E6, "Change color palette  :  C");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 701, 0x00E5E7E6, "Projection  :  V");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 890, 0x00E5E7E6, "Reset  :  R");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 957, 0x00E5E7E6, "Quit  :  ESC");
}


void	draw_line(float x, float y, float x1, float y1, t_data *data)
{
	float	xincr;
	float	yincr;
	float	err;
	float	z;
	float	z1;

	z = data->tab[(int)y][(int)x];
	z1 = data->tab[(int)y1][(int)x1];
	data->color = color_hub(data, z);
	z /= data->zcoeff;
	z1 /= data->zcoeff;
	if (data->projection == 0)
	{
		isometric(&x, &y, z);
		isometric(&x1, &y1, z1);
	}
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	x += data->xoffset;
	y += data->yoffset;
	x1 += data->xoffset;
	y1 += data->yoffset;
	xincr = x1 - x;
	yincr = y1 - y;
	err = find_max(find_abs(xincr), find_abs(yincr));
	xincr /= err;
	yincr /= err;
	while((int)(x1 - x) || (int)(y1 - y))
	{
		if(x < W_WIDTH && x >= 0 && y < W_HEIGHT && y>= 0)
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
