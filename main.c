/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:50:38 by vsmolii           #+#    #+#             */
/*   Updated: 2019/05/29 18:27:12 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_data(t_struct *data)
{
	data->height = 0;
	data->width = 0;
	data->t_height = 0;
	data->t_width = 0;
	data->flag = 0;
	data->final_x = 0;
	data->final_y = 0;
}

char	*get_token_size(char *line, t_struct *data, int fd)
{
	char	**str_d;

	while (ft_strncmp(line, "Piece", 4) != 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	str_d = ft_strsplit(line, ' ');
	data->t_height = ft_atoi(str_d[1]);
	data->t_width = ft_atoi(str_d[2]);
	free(str_d[0]);
	free(str_d[1]);
	free(str_d[2]);
	free(str_d);
	return (line);
}

char	*fill_token_map(char *line, t_struct *data, int fd)
{
	int		i;
	int		j;

	i = -1;
	free(line);
	get_next_line(fd, &line);
	data->token = (char **)malloc(sizeof(char*) * (data->t_height + 1));
	while (++i < data->t_height)
		data->token[i] = (char *)malloc(sizeof(char) * (data->t_width + 1));
	i = 0;
	while (i < data->t_height)
	{
		j = 0;
		while (j < data->t_width)
		{
			data->token[i][j] = line[j];
			j++;
		}
		data->token[i][j] = '\0';
		i++;
		if (i < data->t_height)
			get_next_line(fd, &line);
	}
	data->token[i] = NULL;
	return (line);
}

void	start_work(char *line, t_struct *data, int fd)
{
	if (data->flag == 0)
	{
		line = get_player(line, data, fd);
		data->flag = 1;
	}
	line = get_map_size(line, data, fd);
	line = create_and_fill_map(line, data, fd);
	line = get_token_size(line, data, fd);
	line = fill_token_map(line, data, fd);
	go_for_logic(data);
	free(line);
}

int		main(void)
{
	int			fd;
	int			flag;
	char		*line;
	t_struct	*data;

	fd = 0;
	flag = 0;
	data = (t_struct *)malloc(sizeof(t_struct));
	init_data(data);
	while (get_next_line(fd, &line) > 0)
	{
		start_work(line, data, fd);
	}
	return (0);
}
