/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:47:45 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/30 17:47:48 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		++i;
	}
	return (0);
}
/*DESCRIPTION
	The  memcmp()  function compares the first n bytes (each interpreted as
       unsigned char) of the memory areas s1 and s2.
       The memcmp function compares byte string s1 against byte string s2.
       Both strings are assumed to be n bytes long.
       La funzione mem cmp confronta la stringa di byte s1 con la stringa s2.
       Entrambe le stringhe si presume siano lunghe almeno n byte;
       
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'

   RETURN VALUE
   	 The memcmp() function returns  an  integer  less  than,  equal  to,  or
       greater than zero if the first n bytes of s1 is found, respectively, to
       be less than, to match, or be greater than the first n bytes of s2.

       For a nonzero return value, the sign is determined by the sign  of  the
       difference  between  the  first  pair of bytes (interpreted as unsigned
       char) that differ in s1 and s2.

       If n is zero, the return value is zero.
       
       La funzione memcmp restituisce 0 se le due stringhe sono identiche,
       in caso contrario restituisce la differenza tra i primi due byte diversi
       (trattati come valori di caratteri senza segno, in modo che '\200'
       sia maggiore di '\0', per esempio)
       Le stringhe di lunghezza 0 sono sempre identiche.
       Questo comportamento non e' richiesto da C e il risultato riportato
       dovrebbe dipendere solo dal segno del valore restituito.

       memcmp() confronta le stringhe di byte. Funziona in modo simile alla
       funzione strncmp(). La differenza qui è che memcmp() funziona con stringhe
       di byte quindi accetta puntatori void come parametro, più un terzo
       carattere, che rappresenta, come detto nel man, la lunghezza presunta di
       entrambe le stringhe. Ciò significa che memcmp() non confronterà più di n
       byte. Il valore restituito dipende dalla differenza trovata.
       Se non c'è differenza tra le due stringhe, il valore restituito sarà 0.
       Se c'è una differenza e il primo carattere diverso in s2 è maggiore del
       carattere nella stessa posizione in s1, il risultato restituito sarà
       negativo. Se c'è una differenza e il primo carattere diverso in s2 è 
       inferiore al carattere nella stessa posizione in s1, il risultato
       restituito sarà positivo.
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	string1[] = "Biu";
	char	string2[] = "Bau";
	size_t	n = 3;
	printf("%d\n",ft_memcmp(string1, string2, n));
	printf("%d\n\n",memcmp(string1, string2, n));
	char	str1[] = "Bau";
	char	str2[] = "Bau";
	printf("%d\n",ft_memcmp(str1, str2, n));
	printf("%d\n\n",memcmp(string1, string2, n));
	char	s1[] = "\200";
	char	s2[] = "\0";
	printf("%d\n",ft_memcmp(s1, s2, n));
	printf("%d\n\n",ft_memcmp(string1, string2, n));
	
	return (0);
}
*/
