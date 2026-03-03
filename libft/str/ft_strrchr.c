/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:35:34 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/26 19:35:37 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if ((char)c == *(s + len))
			return ((char *)(s + len));
		--len;
	}
	return (NULL);
}
/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   RETURN VALUE
	CHE COSA RITORNA LA FUNZIONE
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	v[] = "Hello world";
	printf("%s\n", ft_strrchr(v, 'w'));	
	printf("%s\n\n", strrchr(v, 'w'));
	printf("%p\n", ft_strrchr(v, 'w'));	
	printf("%p\n", strrchr(v, 'w'));	
}
*/
