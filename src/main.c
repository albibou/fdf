/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/02/03 20:02:20 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_file(char **av, t_data *data)
{
	int		fd;
	int		test;
	char	*string;

	string = malloc(sizeof(char) * 1);
	if (!string)
		exit(1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		free(string);
		free(data);
		exit(1);
	}
	test = read(fd, string, 1);
	string[0] = '\0';
	if (test <= 0)
	{
		ft_printf("Use it as : './fdf mapname.fdf'\n");
		free(data);
		free(string);
		exit(1);
	}
	free(string);
	return (0);
}

static int	fdf(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (data->img.mlx_img == 0)
	{
		data->error = 5;
		freeerror(data);
	}
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (data->img.addr == 0)
	{
		data->error = 6;
		freeerror(data);
	}
	display_map(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, &manage_event, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, &close_window, data);
	mlx_do_key_autorepeatoff(data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
		exit(1);
	if (ac != 2)
	{
		ft_printf("Use it as : './fdf mapname.fdf'\n");
		free(data);
		exit(1);
	}
	check_file(av, data);
	first_init(data, av);
	init_values(data);
	fdf(data);
	return (0);
}
