/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:39:02 by atardif           #+#    #+#             */
/*   Updated: 2023/01/27 19:39:26 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     manage_event(int keysym, t_data *data)
{
        ft_printf("%d\n", keysym);
        if(keysym == 65307)
        {
                mlx_loop_end(data->mlx_ptr);
                freedata(data);
                exit(0);
        }
        else if (keysym == 112)
                data->zoom += 1;
        else if (keysym == 108 && data->zoom >= 3)
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
        else if (keysym == 118 && data->projection < 2)
                data->projection += 1;
        else if (keysym == 118 && data->projection == 2)
                data->projection = 0;
        else if (keysym == 99 && data->palette == 2)
                data->palette = 0;
        else if (keysym == 99 && data->palette < 2)
                data->palette += 1;
        else if (keysym == 114)
        {
                data->palette = 0;
                data->projection = 0;
                init_values(data);
        }
        //mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
        display_map(data);
        return (0);
}
