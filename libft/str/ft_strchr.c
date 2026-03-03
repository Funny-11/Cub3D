/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:35:16 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/26 19:35:19 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		s++;
	if (*s)
		return ((char *)s);
	else if (!*s && 0 == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
	Trova la lettera passatale come int c all'interno della stringa
	passatale
   CHANGE_LOG
   	Libreria stdio.h non presente perche' inserita in libft.h
   RETURN VALUE
	CHE COSA RITORNA LA FUNZIONE
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	*string = "Cactus";
	
	printf("%s\n", ft_strchr(string, 't'));
	printf("%s\n", strchr(string, 't'));
	printf("%p\n", ft_strchr(string, 't'));
	printf("%p\n\n", strchr(string, 't'));
	
	printf("%s\n", ft_strchr(string, 's'));
	printf("%s\n", strchr(string, 's'));
	printf("%p\n", ft_strchr(string, 's'));
	printf("%p\n\n", strchr(string, 's'));
	
	printf("%s\n", ft_strchr(string, 'A'));
	printf("%s\n", strchr(string, 'A'));
	printf("%p\n", ft_strchr(string, 'A'));
	printf("%p\n\n", strchr(string, 'A'));
	
	printf("%s\n", ft_strchr(string, '\0'));
	printf("%s\n", strchr(string, '\0'));
	printf("%p\n", ft_strchr(string, '\0'));
	printf("%p\n\n", strchr(string, '\0'));

	char	*s1 = "";
	printf("%s\n", ft_strchr(s1, '\0'));
	printf("%s\n", strchr(s1, '\0'));
	printf("%p\n", ft_strchr(string, '\0'));
	printf("%p\n\n", strchr(string, '\0'));
	return (0);
}*/
