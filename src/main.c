/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/01/10 11:36:41 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

typedef	struct s_data
{
	int	height;
	int	width;
	int	**tab;
	char	**av;
} 	t_data;

void	free_tab(char **tab)
{
	char	**tmp;

	tmp = tab;
	while(*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(tab);
}

int	get_width(t_data *data)
{
	int	i;
	int	fd;
	char	*line;
	char	**tab;

	i = 0;
	fd = open(data->av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	tab = ft_split(line, ' ');
	while (tab[i])
		i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	free_tab(tab);
	return (i);
}

int	get_height(t_data *data)
{
	int	i;
	int	fd;
	char	*line;

	i = 0;
	fd = open(data->av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i += 1;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

int	*filltab(int *ltab, char *line, t_data *data)
{
	int	i;
	char 	**sp;

	i = 0;
	sp = ft_split(line, ' ');
	while(i < data->width)
	{
		ltab[i] = ft_atoi(sp[i]);
		i++;
	}
	ltab[i] = 0;
	free_tab(sp);
	return (ltab);
}


int	**init_tab(t_data *data)
{
	int	**tab;
	int	i;
	int	fd;
	char	*line;

	i = 0;
	tab = malloc(sizeof(int *) * (data->height + 1));
	fd = open(data->av[1], O_RDONLY);
	if (fd == -1 || !tab)
		return (NULL);
	line = get_next_line(fd);
	while (i < data->height)
	{
		tab[i] = malloc(sizeof(int) * (data->width));
		tab[i] = filltab(tab[i], line, data);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	tab[i] = 0;
	free(line);
	close (fd);
	return (tab);
}	

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data	*data;
	int	i;
	int	y;

	data = malloc(sizeof(t_data) * 1);
	data->av = av;
	data->height = get_height(data);
	data->width = get_width(data);
	data->tab = init_tab(data);
	i = 0;
	while (i < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			printf("%3d", data->tab[i][y]);
			y++;
		}
		printf("\n");
		i++;
	}
	free(data);
	return (0);
}
