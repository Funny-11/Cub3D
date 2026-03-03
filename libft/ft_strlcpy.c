/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:48:21 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/08 19:49:07 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
	1.controllo dimensione della dimensione, se size e' 0 
	non copiare nulla aiuta a prevenire il buffer overflow.
	2.copiare la stringa src in dest fino a max size -1 questo 
	perche' strlcpy lascia spazio per il terminatore '\0' a fine stringa
	3. dopo la copia strlcpy aggiunge il terminatore null alla fine di dest
	questo garantisce che dest sia sempre un a stringa valida.
	4. resituzione della lunghezza, la funzione restituisce la lunghezza
	totale di src, se la lunghezza restituita e' maggiore o uguale a size
	significa che il buffer dest era troppo piccolo per contenere
	l'intera stringa src.
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   	
   RETURN VALUE
	CHE COSA RITORNA LA FUNZIONE
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	string[] = "Bidibibodibibu";
	char	dest[20];
	size_t	n = 0;
	int	x;
	
	printf("Stringa prima della funzione = %s\n", string);
	printf("dest prima della funzione = %s\n", dest);
	x = ft_strlcpy( dest, string, n);
	printf("Stringa dopo la funzione = %s\n", string);
	printf("dest dopo la funzione = %s\n", dest);
	printf("la lunghezza della stringa sorgente e'= %i\n", x);
}
*/
