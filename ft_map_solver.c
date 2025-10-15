/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:18:48 by iergin            #+#    #+#             */
/*   Updated: 2025/10/15 00:09:03 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	map_solve_helper(int **n, int x, int y)
{
	if (n[x][y] == 0)
		return (0);
	return (min(n[x][y - 1], n[x - 1][y], n[x - 1][y - 1]) + 1);
}

void	map_solver(int **nums)
{
	int	i;
	int	j;

	i = 1;
	while (i < g_map_data.rows)
	{
		j = 1;
		while (j < g_map_data.cols)
		{
			nums[i][j] = map_solve_helper(nums, i, j);
			j++;
		}
		i++;
	}
}

void	fill_square(int top, int left, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			g_map_data.grid[top + i][left + j] = g_map_data.full;
			j++;
		}
		i++;
	}
}

void	scan_row(int **nums, int row, int *best)
{
	int	j;

	j = 0;
	while (j < g_map_data.cols)
	{
		if (nums[row][j] > best[0])
		{
			best[0] = nums[row][j];
			best[1] = row;
			best[2] = j;
		}
		j++;
	}
}

void	mark_biggest_square(int **nums)
{
	int	i;
	int	best[3];

	best[0] = 0;
	best[1] = 0;
	best[2] = 0;
	i = 0;
	while (i < g_map_data.rows)
	{
		scan_row(nums, i, best);
		i++;
	}
	if (best[0] > 0)
		fill_square(best[1] - best[0] + 1, best[2] - best[0] + 1, best[0]);
}
