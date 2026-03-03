/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:49:45 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/07 15:16:14 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_result;
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len_result = ft_strlen(s1) + ft_strlen(s2);
	result = ft_calloc((len_result + 1), sizeof(char));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	return (result);
}
/* DESCRIPTION
	/ENG/
	Allocate (with malloc(3)) and returns a new string resulting from the
	concatenation of s1 and s2.
	/ITA/
	Questa funzione funziona sostanzialmente allo stesso modo di ft_strlcat,
	ma invece di passarle una stringa di destinazione che deve essere
	allocata correttamente come parametro, passiamo solo due stringhe e
	ft_strjoin allocherà la memoria richiesta per entrambe più il 
	NUL-terminating carattere.
	s1 sarà la prima stringa nel risultato, s2 la seconda.
	Dobbiamo ottenere la lunghezza di entrambe le stringhe in modo da poter
	allocare memoria sufficiente per entrambe.
	Quindi copiamo s1 nella nostra stringa appena allocata, quindi copiamo
	s2 e infine possiamo impostare l'ultimo carattere come NUL.
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   	
   RETURN VALUE
	ft_strjoin() returns the new string; NULL if the memory allocation failed.
----------------------------------------------------------------------------
*/
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "Adesso non posso ne' scendere ";
	char	*s2 = NULL;
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}
*/
