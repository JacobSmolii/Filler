/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:12:11 by vsmolii           #+#    #+#             */
/*   Updated: 2019/05/29 12:31:44 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*get_player(char *line, t_struct *data, int fd)
{
	while (ft_strncmp(line, "$$$ exec p", 9) != 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	if (line[10] == '1')
	{
		data->player = 'O';
		data->enemy = 'X';
	}
	else
	{
		data->player = 'X';
		data->enemy = 'O';
	}
	return (line);
}

char	*get_map_size(char *line, t_struct *data, int fd)
{
	char	**str_d;

	while (ft_strncmp(line, "Plateau ", 7) != 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	str_d = ft_strsplit(line, ' ');
	data->height = ft_atoi(str_d[1]);
	data->width = ft_atoi(str_d[2]);
	free(str_d[0]);
	free(str_d[1]);
	free(str_d[2]);
	free(str_d);
	return (line);
}

char	*fill_line(char *line, t_struct *data)
{
	int		i;
	int		start_point;
	char	*new_line;

	i = 0;
	new_line = (char *)malloc(sizeof(char) * (data->width + 1));
	start_point = 4;
	while (i < data->width)
	{
		new_line[i] = line[start_point];
		i++;
		start_point++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*create_and_fill_map(char *line, t_struct *data, int fd)
{
	int		i;

	i = -1;
	while (ft_strncmp(line, "000", 3) != 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	if (!(data->map = (char **)malloc(sizeof(char*) * (data->height + 1))))
		return (NULL);
	while (++i < data->height)
	{
		data->map[i] = fill_line(line, data);
		free(line);
		get_next_line(fd, &line);
	}
	data->map[i] = NULL;
	return (line);
}
