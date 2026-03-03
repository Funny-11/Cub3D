/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:48:39 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/20 16:48:42 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l_dest;
	size_t	l_src;
	size_t	i;

	l_dest = ft_strlen(dest);
	l_src = ft_strlen(src);
	i = 0;
	if (size <= l_dest)
		return (l_src + size);
	while (src[i] != '\0' && ((l_dest + i) < (size - 1)))
	{
		dest[l_dest + i] = src[i];
		i++;
	}
	dest[l_dest + i] = '\0';
	return (l_dest + l_src);
}
/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
	Le funzioni strlcpy() e strlcat() restituiscono la lunghezza
	totale del file stringa che hanno cercato di creare.Per strlcpy() 
	significa la lunghezza di src.
	Per strlcat() ciò significa la lunghezza iniziale di dst più la
	lunghezza di src.Anche se questo può sembrare un po' confuso,è stato
	fatto per rendere troncato il rilevamento del troncamento.
	Si noti, tuttavia, che se strlcat() attraversa i caratteri size
	senza find eseguendo un NUL, la lunghezza della stringa viene
	considerata come dimensione e il des la stringa di colorazione
	non avrà terminazione NUL (poiché non c'era spazio per il NUL).
	Ciò impedisce a strlcat() di scappare dalla fine di una stringa.
	In pratica ciò non dovrebbe accadere (poiché significa che
	entrambe le dimensioni sono incorrect o che dst non è una
	stringa "C" corretta).
	Il controllo esiste per presfogare potenziali problemi di sicurezza
	nel codice errato.
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   	
   RETURN VALUE
	CHE COSA RITORNA LA FUNZIONE
----------------------------------------------------------------------------
*/
/*
int	main()
{
	char	string1[] = "E' stato un piacere tesoro, ";
	char	string2[] = "e' stato un piacioro!";
	size_t	n = 50;
	
	
	printf ("La stringa dest e':%s\nLa stringa src e':%s\n", string1, string2);
	size_t	l = ft_strlcat(string1, string2, n);
	printf ("La stringa dest e':%s\n", string1);
	printf ("La lunghezza della stringa post concatenazione e': %zu\n", l);
	return (0);
}
*/
