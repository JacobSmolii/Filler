/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:17:27 by vsmolii           #+#    #+#             */
/*   Updated: 2019/05/29 18:29:23 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**create_new_map(t_struct *data, int **new_map)
{
	int	i;
	int	j;

	new_map = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = -1;
	while (++i < data->height)
	{
		j = -1;
		new_map[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		while (++j < data->width)
		{
			if (data->map[i][j] == '.')
				new_map[i][j] = -1;
			else if (data->map[i][j] == data->player ||
					data->map[i][j] == data->player + 32)
				new_map[i][j] = -2;
			else if (data->map[i][j] == data->enemy ||
					data->map[i][j] == data->enemy + 32)
				new_map[i][j] = 1;
		}
		new_map[i][j] = 0;
	}
	new_map[i] = NULL;
	return (new_map);
}

int		find_checker(t_struct *data, int **new_map, int i, int j)
{
	if (new_map[i][j + 1] && new_map[i][j + 1] == data->checker)
		return (1);
	else if (j != 0 && new_map[i][j - 1] == data->checker)
		return (1);
	else if (new_map[i + 1] && new_map[i + 1][j] == data->checker)
		return (1);
	else if (i != 0 && new_map[i - 1][j] == data->checker)
		return (1);
	else if (i != 0 && new_map[i - 1][j + 1] &&
			new_map[i - 1][j + 1] == data->checker)
		return (1);
	else if (new_map[i + 1] && new_map[i + 1][j + 1] &&
			new_map[i + 1][j + 1] == data->checker)
		return (1);
	else if (j != 0 && new_map[i + 1] && new_map[i + 1][j - 1] == data->checker)
		return (1);
	else if (i != 0 && j != 0 && new_map[i - 1][j - 1] == data->checker)
		return (1);
	return (0);
}

int		fill_ascend_nbr(t_struct *data, int **new_map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (new_map[i][j] == -1)
			{
				if (find_checker(data, new_map, i, j) == 1)
				{
					flag = 1;
					new_map[i][j] = data->checker + 1;
				}
			}
			j++;
		}
		i++;
	}
	return (flag);
}

void	fill_leftovers(int **new_map, t_struct *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (new_map[i][j] == -1)
				new_map[i][j] = 100000;
			++j;
		}
		++i;
	}
}

int		**heat_map_(t_struct *data)
{
	int	**new_map;

	data->checker = 1;
	new_map = NULL;
	new_map = create_new_map(data, new_map);
	while (fill_ascend_nbr(data, new_map) == 1)
		data->checker++;
	fill_leftovers(new_map, data);
	return (new_map);
}
