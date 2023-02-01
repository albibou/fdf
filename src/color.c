/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:23:22 by atardif           #+#    #+#             */
/*   Updated: 2023/02/01 14:30:20 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	getratio(t_data *data, int z)
{
	float	ratio;

	if (z > 0)
		ratio = ((float)z / (float)data->zmax) * 100;
	else if (z < 0)
		ratio = -((float)z / (float)data->zmin) * 100;
	else
		ratio = 0;
	return (ratio);
}

static int	color_fadea(t_data *data, int z)
{
	int	ratio;

	ratio = getratio(data, z);
	if (ratio == 0)
		return (0x00ffffff);
	else if (ratio > 0 && ratio <= 33)
		return (0x0080ff88);
	else if (ratio > 33 && ratio <= 66)
		return (0x0040ff4d);
	else if (ratio > 66)
		return (0x0000ff11);
	else if (ratio < 0 && ratio >= -33)
		return (0x00ff8080);
	else if (ratio < -33 && ratio >= -66)
		return (0x00ff2b2b);
	else
		return (0xff0000);
}

static int	color_fadeb(t_data *data, int z)
{
	int	ratio;

	ratio = getratio(data, z);
	if (ratio == 0)
		return (0x007aa95c);
	else if (ratio > 0 && ratio <= 33)
		return (0x005D7052);
	else if (ratio > 33 && ratio <= 66)
		return (0x0093441A);
	else if (ratio > 66)
		return (0x00E5E7E6);
	else if (ratio < 0 && ratio >= -33)
		return (0x0004BBFF);
	else if (ratio < -33 && ratio >= -66)
		return (0x000594D0);
	else
		return (0x00003C57);
}

static int	color_fadec(t_data *data, int z)
{
	int	ratio;

	ratio = getratio(data, z);
	if (ratio == 0)
		return (0x0000ff00);
	else if (ratio > 0 && ratio <= 33)
		return (0x0000ffff);
	else if (ratio > 33 && ratio <= 66)
		return (0x000000ff);
	else if (ratio > 66)
		return (0x008000ff);
	else if (ratio < 0 && ratio >= -33)
		return (0x00ffff00);
	else if (ratio < -33 && ratio >= -66)
		return (0x00ff8000);
	else
		return (0x00ff0000);
}

int	color_hub(t_data *data, int z)
{
	if (data->palette == 0)
		return (color_fadea(data, z));
	else if (data->palette == 1)
		return (color_fadeb(data, z));
	else
		return (color_fadec(data, z));
}
