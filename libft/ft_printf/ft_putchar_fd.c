/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:38 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/30 17:52:40 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/* DESCRIPTION
	/ENG/
	PARAMETERS:
	c: character to write
	fd: file descriptor on which to write.

	The ft_putchar_fd() function writes the character c on the file
	descriptor fd.
	/ITA/
	Dai un'occhiata al man per la funzione write(2), il primo parametro è...
	Hai indovinato! Un descrittore di file.
   	EXTERNAL FUNCTS
   	Write(man 2 write)
	RETURN VALUE
	ft_putchar_fd() does not return anything.
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	printf("%\n", ft_putchar_fd('b'));
	return (0);
}*/
