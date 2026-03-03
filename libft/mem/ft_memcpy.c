/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:43:01 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/19 11:43:03 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (src == NULL && dst == NULL)
		return (dst);
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	while (n > 0)
	{
		*(p_dst++) = *(p_src++);
		n--;
	}
	return (dst);
}
/* DESCRIPTION
	ENG
       The memcpy function copies n byte from memory area src to memory area dst.
       If dst and src overlap, behavior is undefined.
       Applications in which dst and src might overlap should use
       memmove(3) instead.
	ITA
       La memcpy copia al massimo n byte da src a dst. Il man parla di
       overlapping ovvero di sovrapposizione di memoria.
       Cos'e' il memory overlapping?
       Supponiamo di avere un array di 5 caratteri, dove ogni carattere e'
       lungo un byte
		+++++++++++++++++++++++++++++++
		| 'a' | 'b' | 'c' | 'd' | 'e' |
		+++++++++++++++++++++++++++++++
		 0x100 0x101 0x102 0x103 0x104
	Cosa succede se dst e' 0x102, src e' 0x100 e n e' 3?
	Si verifica una Sovrapposizione di memoria, vale a dire che 
	0x100 verrebbe copiato in 0x102,
	0x101 verrebbe copiato in 0x103,
	0x102 verrebbe copiato in 0x104 (NB: nota che prima abbiamo copiato 0x100
	in 0x102 il che significa che il valore originale ('a') e' andato perso.
	Quindi finiremmo per avere come risultato qualcosa come:
		+++++++++++++++++++++++++++++++
		| 'a' | 'b' | 'a' | 'b' | 'a' |
		+++++++++++++++++++++++++++++++
 		 0x100 0x101 0x102 0x103 0x104
 	ANZICHE':
 		+++++++++++++++++++++++++++++++
		| 'a' | 'b' | 'a' | 'b' | 'c' |
		+++++++++++++++++++++++++++++++
 		 0x100 0x101 0x102 0x103 0x104
 	Detto cio' memcpy funziona come strcpy solo che memcpy accetta void *
 	come parametro, quindi possiamo fornirle qualsiasi tipo di puntatore
 	che vogliamo copiare.
   RETURN VALUE
   	The memcpy function returns a pointer to (the original value of) dst.
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	string[] = "Bidibibodibibu";
	char	dest[20];
	size_t	n = 6;

	printf("Stringa prima della funzione = %s\n", string);
	printf("dest prima della funzione = %s\n\n", dest);
	ft_memcpy(dest, string, n);
	printf("Stringa dopo la funzione = %s\n", string);
	printf("dest dopo la funzione = %s\n\n", dest);
}
*/
