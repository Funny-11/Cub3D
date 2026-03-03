/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:47:30 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/10 15:46:44 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	str = (const unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
		n--;
	}
	return (NULL);
}
/* DESCRIPTION
	ENG
	The  memchr()  function  scans  the  initial n bytes of the memory area
       pointed to by s for the first instance of c.  Both c and the  bytes  of
       the memory area pointed to by s are interpreted as unsigned char.
       
       The memchr() function locates the first occurrence of c (converted to
       an unsigned char) in string s.
       ITA
       La funzione memchr funziona come la funzione strchr, la differenza e'
       che memchr lavora con stringhe di byte (void *) mentre strchr lavora
       con stringhe di caratteri (char *)
       Cio' significa che potremmo inviare qualsiasi tipo di dato desideriamo
       a memchr e tutto funzionera' comunque.
       Il parametro n dice alla funzione quanti byte vogliamo cercare 
       Abbiamo bisogno di questo parametro poiché s non è una stringa di
       caratteri, non ha un carattere NUL-terminating. Se non avessimo questo
       parametro, leggeremmo un numero casuale di byte ogni volta.
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   RETURN VALUE
   	ENG
   	The  memchr()  and memrchr() functions return a pointer to the matching
       byte or NULL if the character does not occur in the given memory area.
       ITA
   	Le funzioni memchr() e memrchr() restituiscono un puntatore alla
   	corrispondenza byte o NULL se il carattere non si trova nell'area
   	di memoria specificata(ovvero all'interno di n byte).
----------------------------------------------------------------------------
*/
/*
#include <string.h>

int	main(void)
{
	char	*v = "Hello world";
	int	c = 'w';
	size_t	n = 8;

	//printf("%s\n\n",(unsigned char*)ft_memchr(v, c, n));	
	printf("%s\n\n", (unsigned char*)memchr(v, c, n));
	//printf("%p\n", (unsigned char*)ft_memchr(v, c, n));	
	printf("%p\n", (unsigned char*)memchr(v, c, n));
	return (0);
}
*/
