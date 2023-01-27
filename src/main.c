/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/01/27 14:32:19 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	find_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	find_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	find_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	find_zcoeff(t_data *data)
{
	int	ztemp;
	int	rapport;
	int	coeff;

	rapport = find_min(data->height, data->width);
	ztemp = data->zmax;
	coeff = 1;
	while ((ztemp / coeff > rapport / 10))
		coeff += 1;
	return (coeff);
}

void	find_offsets(t_data *data)
{
	data->xoffset = ((W_WIDTH + 400 - data->width * (data->zoom)) / 2);
	data->xoffset += data->height * (data->zoom / 2);
	data->yoffset = (W_HEIGHT - data->height * (data->zoom)) / 2;
	//data->yoffset -= (data->height * data->zoom) / 2;
}

int	find_zoom(t_data *data)
{
	float	ratio;

	if(data->height > data->width)
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

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data	*data;
	int	i;
	int	y;

	data = malloc(sizeof(t_data) * 1);
	data->av = av;
	data->tab = init_tab(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, W_NAME);
	data->zmax = 0;
	data->zmin = 0;
	data->palette = 0;
	data->projection = 0;
	i = 0;
	while (i < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			printf("%3d", data->tab[i][y]);
			if (data->tab[i][y] > data->zmax)
				data->zmax = data->tab[i][y];
			else if (data->tab[i][y] < data->zmin)
				data->zmin = data->tab[i][y];

			y++;
		}
		printf("\n");
		i++;
	}
	data->zcoeff = find_zcoeff(data);
	data->zoom = find_zoom(data);
	find_offsets(data);
	display_map(data);
	mlx_hook(data->win_ptr, 2, 1L<<0, &manage_event, data);
	mlx_loop(data->mlx_ptr);
}
