/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:53:24 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/30 17:53:26 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
/* DESCRIPTION
	/ENG/
	PARAMETERS:
	n: int to write
	fd: file descriptor on which to write

	ft_putnbr_fd() writes the int n on the file descriptor fd
	/ITA/
	Questa funzione funziona allo stesso modo della funzione ft_putnbr()
	che dovevi eseguire durante le Piscine, accetta anche il parametro fd,
	cos'e'? Dai un'occhiata al man per la funzione write(2), il primo
	parametro è...Hai indovinato! Un descrittore di file.
	Non dimenticare che il carattere 0 non è il codice 0 nella tabella
	ASCII, penso che tu possa dare un'occhiata al tuo codice Piscine
	(C05 - Ex04), funziona allo stesso modo.
   	EXTERNAL FUNCTS
   	Write(man 2 write)
	RETURN VALUE
	ft_putnbr_fd() does not return anything
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	ft_putnbr_fd(34, 1);
	return (0);
}
*/
