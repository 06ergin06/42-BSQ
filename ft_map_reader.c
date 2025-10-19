/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:19:58 by iergin            #+#    #+#             */
/*   Updated: 2025/10/19 21:55:34 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	map_error(void)
{
	write(1, "map error\n", 10);
}

void	*free_buf(char *buf)
{
	if (buf)
		free(buf);
	exit(1);
}

int	grow_buffer(char **buf, int *cap, int len)
{
	int		new_cap;
	char	*newb;

	new_cap = (*cap) * 2;
	newb = malloc(new_cap + 1);
	if (!newb)
		return (0);
	ft_strncpy(newb, *buf, len);
	free(*buf);
	*buf = newb;
	*cap = new_cap;
	return (1);
}

char	*ft_read_all(int fd)
{
	char	*buf;
	int		cap;
	int		len;
	int		bytes_read;

	cap = BUFFER_SIZE;
	buf = malloc(cap + 1);
	if (!buf)
		return (NULL);
	len = 0;
	while (1)
	{
		bytes_read = read(fd, buf + len, cap - len);
		if (bytes_read <= 0)
			break ;
		len += bytes_read;
		if (len == cap && grow_buffer(&buf, &cap, len) == 0)
			return (free_buf(buf));
	}
	if (bytes_read < 0)
		return (free_buf(buf));
	buf[len] = '\0';
	return (buf);
}

void	ft_map_reader(char *filepath)
{
	int		fd;
	char	*buffer;
	char	**map;

	if (filepath == NULL)
		fd = 0;
	else
		fd = open(filepath, O_RDONLY);
	if (fd == -1)
		map_error();
	buffer = ft_read_all(fd);
	if (filepath != NULL)
		close(fd);
	if (!buffer)
		map_error();
	if (is_map_content_valid(buffer) == 1)
	{
		map = ft_parse_map(buffer);
		if (!map)
			map_error();
	}
	else
		map_error();
	free(buffer);
}
