/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:49:01 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/07 20:41:30 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}

/* DESCRIPTION
	/ENG/
        The strdup() function allocates sufficient memory for a copy of the
        string s1, does the copy,and returns a pointer to it. The pointer may
        subsequently be used as an argument to the function free(3).
	If insufficient memory is available, NULL is returned and error is set
	to ENOMEM.
	/ITA/
	La funzione strdup() alloca memoria sufficiente per una copia della
	stringa s1, esegue la copia e restituisce un puntatore ad essa.
	Il puntatore può successivamente essere utilizzato come argomento
	per la funzione free(3).Se la memoria disponibile è insufficiente,
	viene restituito NULL e l'errore viene impostato su ENOMEM
	(=error no memory).
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   RETURN VALUE
	CHE COSA RITORNA LA FUNZIONE
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	*s = "E ar popolo?";
	
	printf("%s\n", ft_strdup(s));
	return (0);
}
*/
