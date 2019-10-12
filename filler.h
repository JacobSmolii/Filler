/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:54:13 by vsmolii           #+#    #+#             */
/*   Updated: 2019/05/29 18:29:51 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "stdio.h"
# include <sys/stat.h>
# include <fcntl.h>
# include "stdlib.h"

typedef struct	s_struct
{
	char	**map;
	char	**token;
	int		checker;
	char	player;
	char	enemy;
	int		height;
	int		width;
	int		t_height;
	int		t_width;
	int		final_x;
	int		final_y;
	int		flag;
	int		max_nbr;
}				t_struct;

void			start_work(char *line, t_struct *data, int fd);
char			*fill_token_map(char *line, t_struct *data, int fd);
char			*get_token_size(char *line, t_struct *data, int fd);
void			init_data(t_struct *data);
char			*get_player(char *line, t_struct *data, int fd);
char			*get_map_size(char *line, t_struct *data, int fd);
char			*fill_line(char *line, t_struct *data);
char			*create_and_fill_map(char *line, t_struct *data, int fd);
void			go_for_logic(t_struct *data);
void			check_everything(t_struct *data, int **heat_map, int i, int j);
void			clear_matrix(int ***heat_map, int size);
int				final_rest(t_struct *data, int **heat_map, int i, int j);
int				checking(t_struct *data, int i, int j);
int				**create_new_map(t_struct *data, int **new_map);
int				find_checker(t_struct *data, int **new_map, int i, int j);
int				fill_ascend_nbr(t_struct *data, int **new_map);
int				**heat_map_(t_struct *data);
void			fill_leftovers(int **new_map, t_struct *data);

#endif
