/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:37 by atardif           #+#    #+#             */
/*   Updated: 2023/01/11 18:26:56 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	manage_event(int keysym, t_data *data)
{
	if(keysym == KX_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data.img->mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data.img->mlx_img = NULL;
		data->win_ptr = NULL;
	}
	return (0);
}

int	display_map(t_data *data)
{
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, W_WIDTH, W_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	render_background(&data->img, BACK_BLACK);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return(0);
}