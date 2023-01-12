/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/01/12 14:25:05 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	i = 0;
	while (i < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			printf("%3d", data->tab[i][y]);
			y++;
		}
		printf("\n");
		i++;
	}
	mlx_loop_hook(data->mlx_ptr, &display_map, data);
	mlx_hook(data->win_ptr, 2, 1L<<0, &manage_event, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	//free(data);
}
