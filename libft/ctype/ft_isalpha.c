/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:26:30 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/18 16:26:34 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
   CHANGE_LOG
   	Libreria stdio.h non presente perche' inserita in libft.h
   RETURN VALUE
	(1) se il carattere e' alfabetico (lettere minuscole o maiuscole)
	(0) se non lo e'
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	int	x;

	x = 'g';
	printf ("%d\n", ft_isalpha(x));
	x = 'H';
	printf ("%d\n", ft_isalpha(x));
	x = '?';
	printf ("%d\n", ft_isalpha(x));
}
*/
