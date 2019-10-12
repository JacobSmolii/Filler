/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:05:56 by vsmolii           #+#    #+#             */
/*   Updated: 2019/05/29 18:28:51 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	go_for_logic(t_struct *data)
{
	int i;
	int j;
	int **heat_map;

	i = 0;
	heat_map = heat_map_(data);
	data->max_nbr = 99999999;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			check_everything(data, heat_map, i, j);
			j++;
		}
		i++;
	}
	ft_putnbr(data->final_y);
	ft_putchar(' ');
	ft_putnbr(data->final_x);
	ft_putchar('\n');
	clear_matrix(&heat_map, data->height);
}

void	check_everything(t_struct *data, int **heat_map, int i, int j)
{
	int tmp;

	tmp = 0;
	if (checking(data, i, j) == 1)
	{
		tmp = final_rest(data, heat_map, i, j);
		if (data->max_nbr > tmp)
		{
			data->max_nbr = tmp;
			data->final_y = i;
			data->final_x = j;
		}
	}
}

void	clear_matrix(int ***heat_map, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free((*heat_map)[i++]);
	free(*heat_map);
}

int		final_rest(t_struct *data, int **heat_map, int i, int j)
{
	int x;
	int y;
	int tmp;

	tmp = 0;
	y = 0;
	while (y < data->t_height)
	{
		x = 0;
		while (x < data->t_width)
		{
			if (data->token[y][x] == '*' && heat_map[i + y][j + x] > 0)
				tmp = tmp + heat_map[i + y][j + x];
			x++;
		}
		y++;
	}
	return (tmp);
}

int		checking(t_struct *data, int i, int j)
{
	int x;
	int y;
	int	counter;

	y = -1;
	counter = 0;
	while (++y < data->t_height)
	{
		if (i + y >= data->height)
			return (-1);
		x = -1;
		while (++x < data->t_width)
		{
			if (data->token[y][x] == '*' && (data->map[y + i][x + j] ==
			data->player || data->map[y + i][x + j] == data->player + 32))
				counter++;
			if ((j + x >= data->width) || (data->token[y][x] == '*' &&
					(data->map[y + i][x + j] == data->enemy ||
					data->map[y + i][x + j] == data->enemy + 32)))
				return (-1);
		}
	}
	if (counter != 1)
		return (-1);
	return (1);
}
