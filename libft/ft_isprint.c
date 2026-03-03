/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:04:42 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/18 17:04:46 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
	(1) se il carattere e' stampabile (tabella ascii)
	(0) se non lo e'
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	int	x;

	x = 97;
	printf ("%d\n", ft_isprint(x));
	x = 66;
	printf ("%d\n", ft_isprint(x));
	x = 128;
	printf ("%d\n", ft_isprint(x));
	x = 31;
	printf ("%d\n", ft_isprint(x));
}
*/
