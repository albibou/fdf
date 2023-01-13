/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_inttab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:54:07 by atardif           #+#    #+#             */
/*   Updated: 2023/01/13 17:55:53 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_inttab(int **tab)
{
	int	**tmp;

	tmp = tab;
	while(*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(tab);
}

