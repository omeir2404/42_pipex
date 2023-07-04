/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:10:03 by oharoon           #+#    #+#             */
/*   Updated: 2023/06/06 19:28:48 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

int	word_count(char const *s, char c)
{
	int	word;
	int	is_c;

	word = 0;
	is_c = 0;
	while (*s)
	{
		if (*s != c && is_c == 0)
		{
			is_c = 1;
			word++;
		}
		else if (*s == c)
			is_c = 0;
		s++;
	}
	return (word);
}

char	*create_str(char *str, int i, char **lst, char c)
{
	int		count;
	char	*s;

	count = 0;
	while (*str == c && *str)
		str++;
	while (str[count] && str[count] != c)
		count++;
	s = malloc (sizeof(char ) * (count + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, str, count + 1);
	lst[i] = s;
	return (str + count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		index;
	int		size;
	char	*temp;

	index = -1;
	size = word_count(s, c);
	array = malloc(sizeof(char *) * (size + 1));
	if (!s || !array)
		return (0);
	temp = (char *)s;
	while (++index < size)
		temp = create_str(temp, index, array, c);
	array[size] = NULL;
	return (array);
}
