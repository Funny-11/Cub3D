/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:12:11 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/03 14:12:14 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
	Trasforma ogni carattere che trova da MAIUSCOLO a minuscolo
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   RETURN VALUE
	CHE COSA RITORNA LA FUNZIONE
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	string[] = "SuPeRcAlIfRaGiLiStIcHeSpIrALIdOsO";
	int	i;
	
	i = 0;
	while (string[i] != '\0')
	{
		char lower_char = ft_tolower(string[i]);
		write(1, &lower_char, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
*/
