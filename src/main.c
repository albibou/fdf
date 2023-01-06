/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:43:27 by atardif           #+#    #+#             */
/*   Updated: 2023/01/06 19:44:47 by atardif          ###   ########.fr       */
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

int	get_width(const char *av)
{
	int	i;
	int	fd;
	char	*line;
	char	**tab;

	i = 0;
	fd = open(av, O_RDONLY);
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
	return (i);
}

int	get_height(const char *av)
{
	int	i;
	int	fd;
	char	*line;

	i = 0;
	fd = open(av, O_RDONLY);
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

int	*filltab(int *ltab, char *line)
{
	int	i;
	char 	**sp;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(line);
	sp = ft_split(tmp, ' ');
	while(sp[i])
	{
		ltab[i] = ft_atoi(sp[i]);
		i++;
	}
	free(tmp);
	ltab[i] = 0;
	return (ltab);
}


int	**init_tab(char *av)
{
	int	**tab;
	int	i;
	int	height;
	int	fd;
	char	*line;

	i = 0;
	height = get_height(av);
	tab = malloc(sizeof(int *) * (height + 1));
	fd = open(av, O_RDONLY);
	if (fd == -1 || !tab)
		return (NULL);
	line = get_next_line(fd);
	while (line && i < height)
	{
		tab[i] = malloc(sizeof(int) * (get_width(av) + 1));
		tab[i] = filltab(tab[i], line);
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
	int	**tab;
	int	i;
	int	y;

	tab = init_tab(av[1]);
	i = 0;
	while (tab[i])
	{
		y = 0;
		while (tab[i][y])
		{
			printf("%d", tab[i][y]);
			y++;
		}
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
