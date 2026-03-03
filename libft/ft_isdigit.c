/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:37:38 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/18 16:37:41 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	(1) se il carattere e' numerico (numeri da 0 a 9 in tabella ascii)
	(0) se non lo e'
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	int	x;

	x = '6';
	printf ("%d\n", ft_isdigit(x));
	x = '0';
	printf ("%d\n", ft_isdigit(x));
	x = '9';
	printf ("%d\n", ft_isdigit(x));
	x = 'f';
	printf ("%d\n", ft_isdigit(x));
}
*/
