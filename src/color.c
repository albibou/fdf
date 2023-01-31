/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:23:22 by atardif           #+#    #+#             */
/*   Updated: 2023/01/24 16:40:27 by atardif          ###   ########.fr       */
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
		return (0x00e2e9c9);
	else if (ratio > 0 && ratio <= 33)
		return (0x00bfd49f);
	else if (ratio > 33 && ratio <= 66)
		return (0x009dbe7d);
	else if (ratio > 66)
		return (0x007aa95c);
	else if (ratio < 0 && ratio >= -33)
		return (0x00d3af97);
	else if (ratio < -33 && ratio >= -66)
		return (0x00bb4e54);
	else
		return (0x00a7001e);
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
		return (0x000B162C);
	else if (ratio > 0 && ratio <= 33)
		return (0x0026496a);
	else if (ratio > 33 && ratio <= 66)
		return (0x004889b8);
	else if (ratio > 66)
		return (0x005cafe7);
	else if (ratio < 0 && ratio >= -33)
		return (0x00482a48);
	else if (ratio < -33 && ratio >= -66)
		return (0x00c25381);
	else
		return (0x00ff679d);
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
