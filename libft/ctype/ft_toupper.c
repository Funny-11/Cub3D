/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:11:55 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/03 14:11:58 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
	Trasforma ogni carattere che trova da minuscolo a MAIUSCOLO
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
		char upper_char = ft_toupper(string[i]);
		write(1, &upper_char, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
*/
