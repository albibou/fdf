/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/02/03 20:06:55 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_width(t_data *data)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;

	i = 0;
	fd = open(data->av[1], O_RDONLY);
	if (fd == -1)
	{
		data->error = 1;
		freeerror(data);
	}
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
	ft_freetab(tab);
	return (i);
}

static int	get_height(t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(data->av[1], O_RDONLY);
	if (fd == -1)
	{
		data->error = 1;
		freeerror(data);
	}
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

static int	*filltab(int *ltab, char *line, int index, t_data *data)
{
	int		i;
	char	**sp;

	i = 0;
	sp = ft_split(line, ' ');
	ltab = malloc(sizeof(int) * (data->width));
	if (!ltab)
	{
		data->error = 1;
		ft_free_inttab(data->tab, index);
		freeerror(data);
	}
	while (i < data->width)
	{
		ltab[i] = ft_atoi(sp[i]);
		i++;
	}
	ft_freetab(sp);
	return (ltab);
}

int	**init_tab(t_data *data)
{
	int		**tab;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	data->height = get_height(data);
	data->width = get_width(data);
	tab = malloc(sizeof(int *) * (data->height + 1));
	fd = open(data->av[1], O_RDONLY);
	if (fd == -1 || !tab)
	{
		data->error = 2;
		freeerror(data);
	}
	line = get_next_line(fd);
	while (i < data->height)
	{
		tab[i] = filltab(tab[i], line, i, data);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (close(fd), tab);
}	
