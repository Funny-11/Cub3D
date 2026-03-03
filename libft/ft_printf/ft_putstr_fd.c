/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:50 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/07 15:16:33 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/* DESCRIPTION
   /ENG/
	PARAMETERS:
	s: string to write
	fd: file descriptor on which to write
	Write the string s on the file descriptor fd
   /ITA/
	Dai un'occhiata al man per la funzione write(2), il primo parametro è...
	Hai indovinato! Un descrittore di file.
   EXTERNAL FUNCTS:
   	Write(man 2 write)
   RETURN VALUE:
	ft_putstr_fd() does not return anything.
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	ft_putstr_fd("ciaone", 1);
	return (0);
}
*/
