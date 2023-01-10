/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/01/10 18:08:43 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define	FDF_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../libft/ft_printf.h"

typedef struct	s_data
{
	int	height;
	int	width;
	int	**tab;
	char	**av;
}	t_data;




#endif
