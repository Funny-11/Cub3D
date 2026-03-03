/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:48:33 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/30 17:48:35 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = (number * 10) + (nptr[i] - '0');
		i++;
	}
	return (number * sign);
}
/* DESCRIPTION
	ENG
	The atoi() function converts the initial portion of the string pointed
	to by str to int representation.
	ITA
	La funzione atoi() converte una stringa in un numero/int.
	La stringa passata come parametro può iniziare con un numero arbitrario
	di spazi come determinato da isspace(3).
	Dopo il numero arbitrario di spazi bianchi, può esserci un singolo
	segno opzionale "+" o "-".
	Il resto della stringa verrà convertito in int, fermandosi al primo
	carattere che non è una cifra valida nella base data (nel nostro caso
	dobbiamo gestire solo la base 10, quindi le cifre valide sono 0-9)
	Ho parlato della funzione isspace(3), cos'è quella funzione?
	Funziona allo stesso modo di isdigit, isalpha, ecc. ma restituisce
	un valore diverso da zero quando il carattere è uno dei seguenti:
	\t => tabulation
	\n => new line
	\v => vertical tabulation
	\f => form feed
	\r => carriage return
	' ' => space.
   CHANGE_LOG
   	Libreria stdio.h non presente perche' inserita in libft.h
   RETURN VALUE
   	The converted value.// Restituisce il valore convertito.
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	printf("%d\n", ft_atoi("   \n 	 \t  -34s"));
	return (0);
}
*/
