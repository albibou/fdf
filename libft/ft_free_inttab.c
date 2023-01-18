/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_inttab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:54:07 by atardif           #+#    #+#             */
/*   Updated: 2023/01/18 13:03:55 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_inttab(int **tab, int height)
{
	int	**tmp;
	int	i;

	tmp = tab;
	i = 0;
	while(i < height)
	{
		free(tmp[i]);
		i++;
	}
	free(tab);
}
