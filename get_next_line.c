/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:29:30 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/03 12:07:15 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	*linecpy(char *line, char *new_line, size_t len, char c)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		new_line[i] = line[i];
		i ++;
	}
	new_line[len] = c;
	new_line[len + 1] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*new_line;
	size_t	len;
	char	c;
	ssize_t	bytes_read;

	line = NULL;
	len = 0;
	bytes_read = read(fd, &c, 1);
	while (bytes_read > 0 && c != '\n')
	{
		if (line == NULL)
		{
			line = (char *)malloc(2);
			if (!line)
				return (NULL);
			line[0] = c;
			line[1] = '\0';
			len = 1;
		}
		else
		{
			new_line = (char *)malloc(len + 2);
			if (!new_line)
			{
				free(line);
				return (NULL);
			}
			linecpy(line, new_line, len, c);
			free(line);
			line = new_line;
			len ++;
		}
		bytes_read = read(fd, &c, 1);
	}
	if (bytes_read == -1 || (bytes_read == 0 && len == 0))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/*
int	main()
{
	int	fd = open("/home/amacarul/42_CURSUS/get_next_line/texto1.txt", O_RDONLY, 0644);
	if (fd == -1)
	{
		printf("Error al crear el archivo");
		return (1);
	}
	char *line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return (0);
}*/

/*
int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Uso: %s")
	}
}*/