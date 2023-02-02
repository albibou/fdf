/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/02/02 20:02:46 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file(char **av)
{
	int	fd;
	int	test;
	char	*string;

	string = malloc(sizeof(char) * 1);
	if (!string)
		exit(1);
	fd = open(av[1], O_RDONLY);
	test = read(fd, string, 1);
	string[0] = '\0';
	if (test <= 0)
	{
		ft_printf("Use it as : './fdf mapname.fdf'");
		free(string);
		exit(1);
	}
	free(string);
	return (0);
}

int	main(int ac, char **av)
{
	check_file(av);
	if (ac == 2)
	{
		t_data	*data;

		(void)ac;
		data = malloc(sizeof(t_data) * 1);
		if (!data)
			exit(1);
		first_init(data, av);
		init_values(data);
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
		data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
				&data->img.line_len, &data->img.endian);
		display_map(data);
		mlx_hook(data->win_ptr, 2, 1L << 0, &manage_event, data);
		mlx_hook(data->win_ptr, 17, 1L << 17, &close_window, data);
		mlx_do_key_autorepeatoff(data->mlx_ptr);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_printf("Use it as : './fdf mapname.fdf'");
	return (0);
}
