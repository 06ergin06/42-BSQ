/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:39:07 by iergin            #+#    #+#             */
/*   Updated: 2025/10/15 10:45:18 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	g_map_data;

char	**ft_parse_map(char *buffer)
{
	int		i;
	int		k;
	int		j;
	char	**map;

	i = find_first_newline(buffer);
	g_map_data.empty = buffer[i - 3];
	g_map_data.obstacle = buffer[i - 2];
	g_map_data.full = buffer[i - 1];
	g_map_data.rows = 0;
	j = 0;
	while (j < i - 3)
	{
		if (buffer[j] < '0' || buffer[j] > '9')
			return (NULL);
		g_map_data.rows = g_map_data.rows * 10 + (buffer[j] - '0');
		j++;
	}
	g_map_data.cols = find_first_newline(buffer + i + 1);
	map = malloc(sizeof(char *) * g_map_data.rows);
	k = 0;
	while (k < g_map_data.rows)
		map[k++] = malloc(sizeof(char) * (g_map_data.cols + 1));
	ft_strncpy_2d(map, buffer, i);
	return (g_map_data.grid = map);
}
