/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpoints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:20:37 by atardif           #+#    #+#             */
/*   Updated: 2023/01/27 19:38:52 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	/*float xtemp;
	float   ytemp;

	xtemp = *x;
	ytemp = *y;*/
	*x = (*x - *y) * cos(0.8);
	*y = ((*x + *y) * sin(0.8) - z);
}

void	cabinet(float *x, float *y, int z)
{
	*x = *x + (z * cos(0.8)) / 2;
	*y = *y + (z * sin(0.8)) / 2;
}



