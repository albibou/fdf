/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:31:48 by atardif           #+#    #+#             */
/*   Updated: 2023/01/31 13:44:40 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	find_zlimits(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	while (i < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			if (data->tab[i][y] > data->zmax)
				data->zmax = data->tab[i][y];
			else if (data->tab[i][y] < data->zmin)
				data->zmin = data->tab[i][y];
			y++;
		}
		i++;
	}
}

static int	find_zcoeff(t_data *data)
{
	int	ztemp;
	int	rapport;
	int	coeff;

	rapport = ft_findmin(data->height, data->width);
	ztemp = data->zmax;
	coeff = 1;
	while ((ztemp / coeff > rapport / 10))
		coeff += 1;
	return (coeff);
}

static int	find_zoom(t_data *data)
{
	float	ratio;

	if (data->height > data->width)
		ratio = W_HEIGHT / data->height;
	else
		ratio = W_WIDTH / data->width;
	if (ratio < 2)
		return (2);
	else if (ratio >= 2 && ratio <= 30)
		return (5);
	else if (ratio > 30 && ratio <= 70)
		return (10);
	else
		return (20);
}

void	init_values(t_data *data)
{
	find_zlimits(data);
	data->zcoeff = find_zcoeff(data);
	data->zoom = find_zoom(data);
	data->xoffset = ((W_WIDTH + 400 - data->width * data->zoom) / 2);
	data->xoffset += data->height * (data->zoom / 2);
	data->yoffset = (W_HEIGHT - data->height * data->zoom) / 2;
}

void	first_init(t_data *data, char **av)
{
	data->av = av;
	data->error = 0;
	data->height = 0;
	data->width = 0;
	data->tab = init_tab(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		data->error = 1;
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, W_NAME);
	if (!data->win_ptr)
		data->error = 1;
	data->zmax = 0;
	data->zmin = 0;
	data->palette = 0;
	data->projection = 0;
	data->xoffset = 0;
	data->yoffset = 0;
	data->color = 0;
	data->zoom = 0;
	data->zcoeff = 0;
}
