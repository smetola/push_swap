/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:08:30 by sanmetol          #+#    #+#             */
/*   Updated: 2024/10/02 16:35:46 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		words_number;
	char	**splitted;
	int		i;

	i = 0;
	words_number = count_words(str, separator);
	if (!words_number)
		exit(1);
	splitted = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (NULL == splitted)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			splitted[i] = malloc(sizeof(char));
			if (NULL == splitted[i])
				return (NULL);
			splitted[i++][0] = '\0';
			continue ;
		}
		splitted[i++] = get_next_word(str, separator);
	}
	splitted[i] = NULL;
	return (splitted);
}

char	*join_args(int argc, char **argv)
{
	int		i;
	int		total_length;
	char	*joined;
	int		current_pos;

	i = 1;
	total_length = 0;
	current_pos = 0;
	while (i < argc)
		total_length += ft_strlen(argv[i++]) + 1;
	joined = malloc(total_length * sizeof(char));
	if (!joined)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		ft_strcpy(&joined[current_pos], argv[i]);
		current_pos += ft_strlen(argv[i]);
		if (i < argc - 1)
			joined[current_pos++] = ' ';
		i++;
	}
	joined[current_pos] = '\0';
	return (joined);
}
