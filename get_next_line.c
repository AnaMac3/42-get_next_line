/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:29:30 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/04 12:34:46 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
/*ESTA FUNCIÓN PARTIDA NO FUNCIONA... AVERIGUAR POR QUÉ
char	*process_line(int fd, char *buffer, ssize_t bytes_read)
{
	char	*line;
	ssize_t	i;

	line = NULL;
	buffer[bytes_read] = '\0';
	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			line = ft_strjoin(line, buffer);
			return (line);
		}
		i ++;
	}
	line = ft_strjoin(line, buffer);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}*/

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	ssize_t	i;

	line = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	while (bytes_read > 0)
	{
		//line = process_line(fd, buffer, bytes_read);
		buffer[bytes_read] = '\0';
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
			{
				line = ft_strjoin(line, buffer);
				return (line);
			}
			i ++;
		}
		line = ft_strjoin(line, buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			if (line)
				free(line);
			return (NULL);
		}
	}
	if (!line && bytes_read == 0)
		return (NULL);
	return (line);
}

int	main()
{
	int	fd = open("/home/amacarul/42_CURSUS/get_next_line/texto1.txt", O_RDONLY, 0644);
	if (fd == -1)
	{
		printf("Error al crear el archivo");
		return (1);
	}
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Uso: %s")
	}
}*/