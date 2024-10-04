/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:40:28 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/04 12:27:02 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	count;

	if (s == NULL)
		return (0);
	count = 0;
	while(s[count])
		count ++;
	return (count * sizeof(char));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if(s1 == NULL && s2 == NULL)
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
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j ++;
	}
	joined[i + j] = '\0';
	if (s1 != NULL)
		free(s1);
	return (joined);
}
