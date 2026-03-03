/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:49:27 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/30 17:49:29 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	size_t			i;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	dst = (char *)ft_calloc((len + 1), sizeof(char));
	if (!dst)
		return (NULL);
	while (*s && len > i)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	return ((char *)dst);
}
/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
	Crea una stringa di lunghezza (len) ottenuta a partire dalla posizione
	(start) di s che e' la stringa passatale.
	esempio:
	ft_substr("Bonjour comment ca va?", 5, 8);
	=> "ur comme"
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   	
   RETURN VALUE
	CHE COSA RITORNA LA FUNZIONE
----------------------------------------------------------------------------
*/
/*
#include <stdio.h>

int	main(void)
{
	char	*string = "Bonjour!";
	unsigned int starto = 2;
	size_t lenght = 3;
	
	printf("%s\n", ft_substr(string, starto, lenght));
	return (0);
}
*/
