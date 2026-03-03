/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:38:18 by gifanell          #+#    #+#             */
/*   Updated: 2024/11/28 23:38:22 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *) s;
	while (n--)
		*tmp_ptr++ = c;
	return (s);
}

/* DESCRIPTION
	The memset() function writes n bytes of value c (converted to an
	unsigned char) to the string s.
	
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   	
   RETURN VALUE
   	the memset function returns a pointer to the memory area s
   	(its first argument).
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	string[5] = "ciao";
	//ft_memset(string, 'b', sizeof(string));
	ft_memset(string, 'b', 2);
	printf("%s\n", string);
	return (0);
}
*/
