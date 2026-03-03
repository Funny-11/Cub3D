/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:04:24 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/18 17:04:28 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
	Controlla se il carattere passatole fa' parte della tabella ascii 
	(VERSIONE RIDOTTA DA 0 A 127)
   CHANGE_LOG
   	Libreria stdio.h non presente perche' inserita in libft.h
   RETURN VALUE
	(1) se il carattere e' compreso tra 0 e 127 (tabella ascii)
	(0) se non lo e'
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	int	x;

	x = '5';
	printf ("%d\n", ft_isascii(x));
	x = 'd';
	printf ("%d\n", ft_isascii(x));
	x = 163;
	printf ("%d\n", ft_isascii(x));
	x = 173;
	printf ("%d\n", ft_isascii(x));
	return (0);
}
*/
