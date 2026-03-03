/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:35:50 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/07 15:23:19 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
	Compara due stringhe passatele e restituisce un (char *) dalla
	corrispondenza in poi.
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   RETURN VALUE
	CHE COSA RITORNA LA FUNZIONE
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	*s = "Boia";
	char 	*s1 = "Bona";
	int		n = 4;

	printf("%d\n", ft_strncmp(s, s1, n));
	printf("%d\n", strncmp(s, s1, n));
	return (0);
}
*/
