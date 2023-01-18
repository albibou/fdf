/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:23:22 by atardif           #+#    #+#             */
/*   Updated: 2023/01/18 17:45:38 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	getratio(t_data *data, int z)
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


int	color_fade(t_data *data, int z)
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
