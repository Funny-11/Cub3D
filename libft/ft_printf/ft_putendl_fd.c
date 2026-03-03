/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:53:08 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/10 15:47:22 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
/* DESCRIPTION
	/ENG/
	PARAMETERS:
	s: string to write
	fd: the file descriptor on which to write

	ft_putendl_fd() writes the string s, followed by a newline, on the
	file descriptor fd.
	/ITA/
	FT_PUTSTR_FD MA CON SEGUITO DA UNA NUOVA RIGA.
	Dai un'occhiata al man per la funzione write(2), il primo parametro è...
	Hai indovinato! Un descrittore di file.
   	EXTERNAL FUNCTS
   	Write(man 2 write)
	RETURN VALUE
	ft_putendl_fd() does not return anything
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	ft_putendl_fd("bulo", 1);
	return (0);
}
*/
