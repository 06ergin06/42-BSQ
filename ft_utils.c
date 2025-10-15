/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:50:23 by iergin            #+#    #+#             */
/*   Updated: 2025/10/15 10:53:05 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	find_first_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[n] = '\0';
}

void	ft_strncpy_2d(char **dest, char *src, int start)
{
	int	i;
	int	j;
	int	src_index;

	i = 0;
	src_index = start + 1;
	while (src[src_index] != '\0')
	{
		j = 0;
		while (src[src_index] != '\n' && src[src_index] != '\0')
		{
			dest[i][j] = src[src_index];
			j++;
			src_index++;
		}
		dest[i][j] = '\0';
		if (src[src_index] == '\n')
			src_index++;
		i++;
	}
}

int	min(int num1, int num2, int num3)
{
	int	m;

	m = num1;
	if (num2 < m)
		m = num2;
	if (num3 < m)
		m = num3;
	return (m);
}

int	**replace_numbers(void)
{
	int	i;
	int	j;
	int	**nums;

	nums = malloc(sizeof(int *) * g_map_data.rows);
	i = 0;
	while (i < g_map_data.rows)
	{
		nums[i] = malloc(sizeof(int) * g_map_data.cols);
		j = 0;
		while (j < g_map_data.cols)
		{
			if (g_map_data.grid[i][j] == g_map_data.obstacle)
				nums[i][j] = 0;
			else
				nums[i][j] = 1;
			j++;
		}
		i++;
	}
	return (nums);
}
