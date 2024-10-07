/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:40:28 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/07 13:27:35 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*char_dest;
	const unsigned char	*char_src;
	size_t				pos;

	if (src == NULL || dest == NULL)
		return (NULL);
	char_dest = (unsigned char *) dest;
	char_src = (const unsigned char *) src;
	if (char_dest < char_src || char_dest >= char_src + n)
	{
		pos = 0;
		while (pos < n)
		{
			char_dest[pos] = char_src[pos];
			pos ++;
		}
	}
	else
	{
		char_dest += n;
		char_src += n;
		while (n--)
			*(--char_dest) = *(--char_src);
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	*result;

	result = (char *) s;
	while (*result)
	{
		if (*result == c)
			return (result);
		result ++;
	}
	if (c == '\0')
		return (result);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (s[count])
		count ++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*start_dup;

	if (s == NULL)
		return (NULL);
	dup = (char *)malloc(ft_strlen(s) + 1);
	if (dup == NULL)
		return (NULL);
	start_dup = dup;
	while (*s)
	{
		*dup = *s;
		dup ++;
		s ++;
	}
	*dup = '\0';
	return (start_dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc (total_len + 1);
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i])
	{
		joined[i] = s1[i];
		i ++;
	}
	j = 0;
	while (s2 != NULL && s2[j])
	{
		joined[i + j] = s2[j];
		j ++;
	}
	joined[i + j] = '\0';
	return (joined);
}
