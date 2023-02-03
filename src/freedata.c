/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:06:43 by atardif           #+#    #+#             */
/*   Updated: 2023/02/03 20:09:50 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_error(t_data *data)
{
	if (data->error >= 3)
		ft_printf("MLX error\n");
	else if (data->error == 2 || data->error == 1)
		ft_printf("Open/Alloc error\n");
}

void	freeerror(t_data *data)
{
	display_error(data);
	if (data->error == 6)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (data->error >= 5)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->error >= 4)
		mlx_destroy_display(data->mlx_ptr);
	if (data->error >= 2)
	{
		free(data->mlx_ptr);
		ft_free_inttab(data->tab, data->height);
	}
	free(data);
	exit(1);
}

void	freedata(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free_inttab(data->tab, data->height);
	free(data);
	exit(0);
}
