/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/01/17 16:37:05 by atardif          ###   ########.fr       */
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
#include <X11/keysym.h>
#include <X11/X.h>
#include <math.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../libft/ft_printf.h"

# define W_WIDTH	1000
# define W_HEIGHT	800
# define W_NAME	"Fdf"
# define BACK_BLACK	0x00171717

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

typedef struct	s_data
{
	int	height;
	int	width;
	int 	color;
	int	zoom;
	int	**tab;
	char	**av;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;

}	t_data;

int	get_width(t_data *data);
int	get_height(t_data *data);
int	**init_tab(t_data *data);
int	manage_event(int keysym, t_data *data);
int	display_map(t_data *data);
int	find_max(int x, int y);
int	find_abs(int x);
void	draw_map(t_data *data);
void	draw_line(float x, float y, float x1, float y1, t_data *data);
void	freedata(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);

#endif
