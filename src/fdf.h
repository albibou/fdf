/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/02/01 14:37:03 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"

# define W_WIDTH	1920
# define W_HEIGHT	1080
# define W_NAME	"Fdf"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_points
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	float	z;
	float	z1;
}	t_points;

typedef struct s_data
{
	int			height;
	int			width;
	int			error;
	int			projection;
	int			zmax;
	int			zmin;
	int			palette;
	int			color;
	int			**tab;
	int			zcoeff;
	float		xoffset;
	float		yoffset;
	float		zoom;
	char		**av;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_points	points;

}	t_data;

int		**init_tab(t_data *data);
int		manage_event(int keysym, t_data *data);
int		display_map(t_data *data);
int		close_window(t_data *data);
int		color_hub(t_data *data, int z);
void	find_offsets(t_data *data);
void	draw_map(t_data *data, t_points points);
void	draw_rectangle(t_img *img, int x, int y);
void	first_init(t_data *data, char **av);
void	freedata(t_data *data);
void	init_values(t_data *data);
void	init_points(t_points points);
void	render_background(t_img *img);
void	set_params(t_points *points, t_data *data);

#endif
