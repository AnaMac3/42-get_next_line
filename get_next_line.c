/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:29:30 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/07 16:17:14 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*join_and_free(char *s1, char *s2)
{
	char	*joined;

	if (s1 == NULL)
		return (ft_strdup(s2));
	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

void	shift_buffer(char *buffer, char *newline_pos)
{
	size_t	rest_len;

	if (newline_pos)
	{
		rest_len = ft_strlen(newline_pos + 1);
		ft_memmove(buffer, newline_pos + 1, rest_len + 1);
	}
	else
		buffer[0] = '\0';
}

char	*process_buffer(char *line, char *buffer)
{
	char	*line_temp;
	char	*newline_pos;

	newline_pos = ft_strchr(buffer, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		line_temp = join_and_free(line, buffer);
		if (line_temp)
			line = join_and_free (line_temp, "\n");
		shift_buffer(buffer, newline_pos);
	}
	else
	{
		line_temp = join_and_free(line, buffer);
		line = line_temp;
		buffer[0] = '\0';
	}
	return (line);
}

char	*read_until_newline(int fd, char *buffer, char *line)
{
	ssize_t	bytes_read;

	while (!(ft_strchr(buffer, '\n')))
	{
		if (*buffer)
		{
			line = join_and_free(line, buffer);
			if (line == NULL)
				return (NULL);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read < 0 || !line)
			{
				free (line);
				return (NULL);
			}
			buffer[0] = '\0';
			return (line);
		}
		buffer[bytes_read] = '\0';
	}
	return (process_buffer(line, buffer));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	return (read_until_newline(fd, buffer, line));
}

//Main 1: normal
/*
int	main()
{
	int fd = open("texto1.txt", O_RDONLY, 0644);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	char	*line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/

//Main 2: hay que pasarle el file al ejecutar
/*
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error, introduce el nombre fd a leer\n");
		return (1);
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	char	*line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return (0);
}*/

//Main 3: stdin
/*
int main()
{
	char	*line = get_next_line(0);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}
*/