/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:37 by atardif           #+#    #+#             */
/*   Updated: 2023/01/27 19:45:08 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_instructionbox(t_img *img)
{
	draw_rectangle(img, 0, 56);
	draw_rectangle(img, 0, 312);
	draw_rectangle(img, 0, 568);
	draw_rectangle(img, 0, 824);
}

void	render_instructiontext(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 122, 0x00E5E7E6,
		"Move up / down  :  W / S");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 189, 0x00E5E7E6,
		"Move left / right  :  A / D");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 378, 0x00E5E7E6,
		"Zoom in / out  :  P / L");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 445, 0x00E5E7E6,
		"Decrease / increase height  :  N / M");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 634, 0x00E5E7E6,
		"Change color palette  :  C");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 701, 0x00E5E7E6,
		"Projection  :  V");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 890, 0x00E5E7E6,
		"Reset  :  R");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 957, 0x00E5E7E6,
		"Quit  :  ESC");
}

int	display_map(t_data *data)
{
	render_background(&data->img, data);
	draw_map(data);
	render_instructionbox(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	render_instructiontext(data);
	return (0);
}
