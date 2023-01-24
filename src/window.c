/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:37 by atardif           #+#    #+#             */
/*   Updated: 2023/01/24 18:30:36 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	manage_event(int keysym, t_data *data)
{
	ft_printf("%d\n", keysym);
	if(keysym == 65307)
	{
		freedata(data);
		exit(0);
	}
	else if (keysym == 112)
		data->zoom += 1;
	else if (keysym == 108 && data->zoom > 1)
		data->zoom -= 1;
	else if (keysym == 119)
		data->yoffset -= 10;
	else if (keysym == 115)
		data->yoffset += 10;
	else if (keysym == 97)
		data->xoffset -= 10;
	else if (keysym == 100)
		data->xoffset += 10;
	else if (keysym == 110)
		data->zcoeff += 1;
	else if (keysym == 109 && data->zcoeff > 1)
		data->zcoeff -= 1;
	else if (keysym == 118 && data->projection < 1)
		data->projection += 1;
	else if (keysym == 118 && data->projection == 1)
		data->projection = 0;
	else if (keysym == 99 && data->palette == 2)
		data->palette = 0;
	else if (keysym == 99 && data->palette < 2)
		data->palette += 1;
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	display_map(data);
	return (0);
}






int	display_map(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	render_background(&data->img, data);
	draw_map(data);
	render_instructionbox(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	render_instructiontext(data);
	return(0);
}
