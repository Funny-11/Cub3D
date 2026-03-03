/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:07:59 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/02 16:08:09 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*pdst;
	char	*psrc;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	pdst = (char *)dst;
	psrc = (char *)src;
	if (pdst > psrc)
	{
		i = n;
		while (i > 0)
		{
			pdst[i - 1] = psrc[i - 1];
			i--;
		}
		return ((void *)dst);
	}
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return ((void *)dst);
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
	char	s1[] = "Cazzarola";
	char	s2[20];
	
	printf ("%s\n", (char *)ft_memmove(s2, s1, 3));
	return (0);
}
*/
