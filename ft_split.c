/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikorkut <ikorkut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:37:04 by ikorkut           #+#    #+#             */
/*   Updated: 2022/10/24 12:02:49 by ikorkut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

char	*ft_str_creat(const char *s, char c, size_t i)
{
	size_t	len;
	size_t	tmp;

	len = 0;
	tmp = i;
	while (s[tmp] != c && s[tmp])
	{
		tmp++;
		len++;
	}
	return (ft_substr(s, i, len));
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	return_index;
	char	**return_value;

	if (!s)
		return (0);
	return_value = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!return_value)
		return (0);
	i = 0;
	return_index = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			return_value[return_index] = ft_str_creat(s, c, i);
			return_index++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return_value[return_index] = 0;
	return (return_value);
}
