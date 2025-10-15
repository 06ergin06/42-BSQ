/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:38:34 by iergin            #+#    #+#             */
/*   Updated: 2025/10/15 10:40:40 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	parse_header(char **cursor, int *rows, char sign[3])
{
	int	i;
	int	header_len;

	header_len = 0;
	while ((*cursor)[header_len] && (*cursor)[header_len] != '\n')
		header_len++;
	*rows = 0;
	i = 0;
	while ((*cursor)[i] >= '0' && (*cursor)[i] <= '9')
	{
		*rows = *rows * 10 + ((*cursor)[i] - '0');
		i++;
	}
	if (*rows <= 0 || header_len - i != 3)
		return (0);
	sign[0] = (*cursor)[i];
	sign[1] = (*cursor)[i + 1];
	sign[2] = (*cursor)[i + 2];
	if (sign[0] == sign[1] || sign[0] == sign[2] || sign[1] == sign[2])
		return (0);
	*cursor = *cursor + header_len + 1;
	return (1);
}

int	validate_body(char *cursor, int expected_rows, char sign[3])
{
	int	width;
	int	len;
	int	current_rows;

	width = -1;
	current_rows = 0;
	while (*cursor && current_rows < expected_rows)
	{
		len = 0;
		while (cursor[len] && cursor[len] != '\n')
		{
			if (cursor[len] != sign[0] && cursor[len] != sign[1])
				return (0);
			len++;
		}
		if (width == -1)
			width = len;
		else if (len != width)
			return (0);
		cursor += len;
		if (*cursor == '\n')
			cursor++;
		current_rows++;
	}
	return (current_rows == expected_rows && width > 0 && *cursor == '\0');
}

int	is_map_content_valid(char *buffer)
{
	char	sign[3];
	char	*cursor;
	int		rows;

	if (!buffer || !*buffer)
		return (0);
	cursor = buffer;
	if (parse_header(&cursor, &rows, sign) && validate_body(cursor, rows, sign))
		return (1);
	return (0);
}
