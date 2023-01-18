/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/01/18 17:19:39 by atardif          ###   ########.fr       */
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
	data->zoom = 1;
	data->xoffset = 900;
	data->yoffset = 450;
	data->zcoeff = 1;
	data->zmax = 0;
	data->zmin = 0;
	//data->projection = 0;
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
	display_map(data);
	mlx_hook(data->win_ptr, 2, 1L<<0, &manage_event, data);
	mlx_loop(data->mlx_ptr);
}
