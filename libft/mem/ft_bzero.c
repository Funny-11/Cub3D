/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:42:42 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/19 11:42:46 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp_ptr;
	unsigned char	c;

	tmp_ptr = (unsigned char *) s;
	c = '\0';
	while (n--)
		*tmp_ptr++ = c;
}
/*DESCRIPTION
	ENG
	The bzero function writes n zeroed bytes to the string s. If n is
	zero, bzero() does nothing
	This function works the same way as the memset(), except you don't 
	have to specify what character to write, it'll always be 0
	(NUL character)
	ITA
	Questa funzione funziona allo stesso modo della funzione memset(),
	tranne che non devi specificare quale carattere scrivere, sarà sempre
	0 (carattere NUL).
   CHANGE_LOG
   	Libreria stdio.h non presente perche' inserita in libft.h
   RETURN VALUE
   	None.
   	Questa funzione non restituisce nulla e se il numero di caratteri
	da scrivere che hai passato come size_t n è 0, bzero non fa nulla.
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	string[5] = "ciao";

	ft_bzero(string, 2);
	printf("%s\n", string);
	//printf("%s\n\n", string + 2);
	//bzero(string, 2);
	//printf("%s\n", string);
	//printf("%s\n\n", string + 2);
	return (0);
}
*/
