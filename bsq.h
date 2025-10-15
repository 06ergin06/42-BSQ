/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:13:55 by iergin            #+#    #+#             */
/*   Updated: 2025/10/15 11:07:05 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 4096

typedef struct s_map
{
	int			rows;
	int			cols;
	char		empty;
	char		obstacle;
	char		full;
	char		**grid;
}				t_map;

extern t_map	g_map_data;

void			ft_map_reader(char *filepath);
int				find_first_newline(char *str);
void			ft_strncpy(char *dest, char *src, int n);
void			ft_strncpy_2d(char **dest, char *src, int start);
int				is_map_content_valid(char *buffer);
char			**ft_parse_map(char *buffer);
int				**replace_numbers(void);
int				min(int num1, int num2, int num3);
void			map_solver(int **nums);
int				map_solve_helper(int **nums, int x, int y);
void			mark_biggest_square(int **nums);
void			fill_square(int top, int left, int size);
char			*ft_read_all(int fd);
#endif
