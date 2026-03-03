/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:48:46 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/30 17:48:48 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	total_size;

	total_size = nmemb * size;
	result = malloc(total_size);
	if (!result)
		return (NULL);
	ft_bzero(result, total_size);
	return (result);
}
/* DESCRIPTION
	ENG
	The calloc() function allocates memory.
    The allocated memory is aligned such that it can be used for any data type.
    The calloc() function contigously allocates enough space for count objects
    that are size bytes of memory each and returns a pointer to the allocated
    memory.The allocated memory is filled with bytes of value zero.
	ITA
	A questo punto dovresti aver capito cosa fa la funzione malloc(),
	Calloc() funziona allo stesso modo di malloc(), ma la differenza
	è che calloc() imposta tutti i byte di memoria su 0 invece di rimanere
	come il linguaggio senza senso che era lì in memoria prima che lo
	allocassimo.
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   RETURN VALUE
	Return a pointer to the allocated
       memory, which is suitably aligned for any  built-in  type.   On  error,
       these functions return NULL.
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	*s = "Vaffanculoooo";
	void	*k = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	printf ("%s\n", (char *)k);
	free(k);
	return (0);
}
*/
