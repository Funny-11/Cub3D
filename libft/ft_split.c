/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:04:24 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/08 21:12:19 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_counter_words(const char *string, char c)
{
	int	i;
	int	words_n;
	int	start;

	i = 0;
	words_n = 0;
	start = 1;
	while (string[i] != '\0')
	{
		if (string[i] != c && start)
		{
			words_n++;
			start = 0;
		}
		else if (string[i] == c)
			start = 1;
		i++;
	}
	return (words_n);
}

static char	**dealloc(char **allocated, int j)
{
	int	i;

	i = 0;
	(void)j;
	while (allocated && allocated[i])
	{
		free(allocated[i]);
		i++;
	}
	free(allocated);
	return (NULL);
}

static char	**allocate_word(char **allocated, char const *s, char c)
{
	int	start;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			allocated[j] = ft_substr(s, start, i - start);
			if (!allocated[j])
				return (dealloc(allocated, j));
			j++;
		}
	}
	return (&allocated[j]);
}

char	**ft_split(char const *s, char c)
{
	char	**allocated;
	int		words;
	int		j;

	j = 0;
	words = ft_counter_words(s, c);
	if (!s || s == NULL)
		return (NULL);
	if (s == 0)
		return ((char **)ft_strdup(""));
	allocated = ft_calloc((words + 1), sizeof(char *));
	if (!allocated)
		return (dealloc(allocated, j));
	allocate_word(allocated, s, c);
	return (allocated);
}

/*	
}
 DESCRIPTION
	/ENG/
	Parameters:
	s: The string to be split.
	c: The delimiter character.
	Allocate (with malloc(3)) and returns an array of strings obtained
	by splitting s with the character c, used as delimiter.
	The returned array must be NUL-terminated.
	/ITA/
	
   CHANGE_LOG
   	External functs: malloc (non si possono usare le funzioni 
	originali ma la tua versione si quindi per esempio usare ft_calloc
	va bene perche' richiama il tuo malloc. (non le funzioni originali).
   RETURN VALUE
	The array of new strings resulting from the split.
	NULL if the allocation fails.
----------------------------------------------------------------------------
*/
/*
int	main()
{
	char	*s; //= "c98btahwuofiq";
	char	c = 48;
	int	i;
	char	**result;
	
	i = 0;
	result = ft_split(s, c);
	
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/
