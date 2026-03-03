/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:37:58 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/18 16:38:01 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
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
	(1) se il carattere e' alfanumerico (lettere e/o numeri)
	(0) se non lo e'
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	int	x;

	x = '7';
	printf ("%d\n", ft_isalnum(x));
	x = 'a';
	printf ("%d\n", ft_isalnum(x));
	x = 'V';
	printf ("%d\n", ft_isalnum(x));
	x = '?';
	printf ("%d\n", ft_isalnum(x));
}
*/
