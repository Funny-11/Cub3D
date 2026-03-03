/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:51:51 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/10 15:46:36 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	long	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*allocated;
	int		len;
	long	num;

	num = (long)n;
	len = ft_nlen(n);
	allocated = ft_calloc((len + 1), sizeof(char));
	if (!allocated)
		return (NULL);
	if (num < 0)
	{
		allocated[0] = '-';
		num = -num;
	}
	if (num == 0)
		allocated[0] = '0';
	while (num != 0)
	{
		allocated[--len] = (num % 10) + 48;
		num = num / 10;
	}
	return (allocated);
}

/* DESCRIPTION
	/ENG/
	DESCRIZIONE/SPIEGAZIONE FUNZIONE
	/ITA/
	trasforma un int in un char
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   RETURN VALUE
	The string representing the integer. NULL if the allocation fails.
	Ritorna char * del valore modificato e allocato.
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	*b;
	
	b = ft_itoa(0);
	printf("%s\n", b);
	free(b);
	return (0);
}
*/
