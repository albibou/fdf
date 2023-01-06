#include "./minilibx/mlx.h"
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

typedef struct s_data
{
	void	*mlx;
	void	*win;
} t_data;

typedef struct s_rect
{
	int x;
	int y;
	int width;
	int height;
	int color;
} t_rect;


void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	if (data->win == NULL)
		return;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_pixel_put(data->mlx, data->win, j, i, color);
			j++;
		}
		i++;
	}
}

int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if(data->win == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			mlx_pixel_put(data->mlx, data->win, j, i, rect.color);
			j++;
		}
		i++;
	}
	return (0);
}

int	render(t_data *data)
{
	//render_background(data, WHITE);
	render_rect(data, (t_rect){WIDTH - 200, HEIGHT / 2 - 100, 200, 200, GREEN});
	render_rect(data, (t_rect){0, HEIGHT / 2 - 100, 200, 200, RED});
	render_rect(data, (t_rect){(WIDTH / 2) - 100, (HEIGHT / 2) - 100, 200, 200, BLUE});
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

	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx);

	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
