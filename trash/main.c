#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

# define WIDTH 1000
# define HEIGHT 500

# define MLX_ERROR 1

# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define WHITE 0x00F0FFF0

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
} t_data;

typedef struct s_rect
{
	int x;
	int y;
	int width;
	int height;
	int color;
} t_rect;


void	img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + (( y * img->line_len ) + ( x * (img->bpp / 8)));
	*(int *)pixel = color;
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			img_pix_put(img, j, i, rect.color);
			j++;
		}
		i++;
	}
	return (0);
}

int	render(t_data *data)
{
	render_background(&data->img, WHITE);
	render_rect(&data->img, (t_rect){WIDTH - 200, HEIGHT / 2 - 100, 200, 200, GREEN});
	render_rect(&data->img, (t_rect){0, HEIGHT / 2 - 100, 200, 200, RED});
	render_rect(&data->img, (t_rect){(WIDTH / 2) - 100, (HEIGHT / 2) - 100, 200, 200, BLUE});

	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return(0);
}


int main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "test");
	if(data.win == NULL)
	{
		free(data.win);
		return (MLX_ERROR);
	}

	data.img.mlx_img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx);

	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
