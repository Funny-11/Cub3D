/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:51:07 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/06 22:14:29 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!*s1)
		return (ft_strdup(s1));
	if (NULL == s1 || NULL == set)
		return (NULL);
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		++start;
	while (end >= 0 && ft_strchr(set, *(s1 + end)))
		--end;
	if (start > end)
		return (ft_strdup(""));
	trimmed = ft_calloc((end - start) + 2, (sizeof(char)));
	if (NULL == trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, (end - start) + 2);
	return (trimmed);
}
/* DESCRIPTION
   /ENG/
	Parameters:
	s1: The string to be trimmed.
	set: The reference set of characters to trim.
	Allocates (with malloc(3)) and returns a copy of  ’s1’ with the
	characters specified in ’set’ removed from the beginning and the
	end of the string.
   /ITA/
	Rimuove i caratteri presenti nella stringa set all'inizio e alla fine
	della stringa s1.
   NOTA BENE:
   	External functs: malloc (non si possono usare le funzioni 
	originali ma la tua versione si quindi per esempio usare ft_calloc
	va bene perche' richiama il tuo malloc. (non le funzioni originali).
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   RETURN VALUE
	The trimmed string. NULL if the memory allocation failed.
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	printf("%s\n\n", ft_strtrim("smarosmarisma", "sma"));
	printf("%s\n\n", ft_strtrim("", ""));
	printf("%s\n\n", ft_strtrim("NULL", "sma"));
	return (0);
}*/
