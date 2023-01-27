/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/01/27 18:46:07 by atardif          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	*data;

	(void)ac;
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (1);
	first_init(data, av);
	init_values(data);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	display_map(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, &manage_event, data);
	mlx_do_key_autorepeatoff(data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
}
