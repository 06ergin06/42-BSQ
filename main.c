/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:25:08 by iergin            #+#    #+#             */
/*   Updated: 2025/10/14 23:49:13 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map(void)
{
	int	r;
	int	c;

	r = 0;
	while (r < g_map_data.rows)
	{
		c = 0;
		while (c < g_map_data.cols)
		{
			write(1, &g_map_data.grid[r][c], 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

void	free_nums(int **nums)
{
	int	i;

	i = 0;
	while (i < g_map_data.rows)
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	solve_current_map(void)
{
	int	**nums;

	nums = replace_numbers();
	if (!nums)
		return ;
	map_solver(nums);
	mark_biggest_square(nums);
	print_map();
	free_nums(nums);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		ft_map_reader(NULL);
		solve_current_map();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		ft_map_reader(argv[i]);
		solve_current_map();
		if (i + 1 < argc)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
