/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:07 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/08 19:49:23 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char ft_letstry(unsigned int c, char s)
{
    int l;
    l = c % 2;
    if (l == 0)
        s = s - 32;
    else
        return (s);
    return (s);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*allocated;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	allocated = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!allocated)
		return (NULL);
	while (i < ft_strlen(s))
	{
		allocated[i] = f(i, s[i]);
		i++;
	}
	return (allocated);
}

/*applica una funzione a ogni carattere di una stringa (come striteri) e la
trascrive in un nuovo spazio di memoria allocata cosi da non modificare la
stringa originale*/
/*
 int  main(void)
{
    const char      s[] = "diomerdafunziona";
    char            *l;
    unsigned int    i;
    
    i = 0;
    l = ft_strmapi(s, ft_letstry);
    printf("l'array allocato e' %s\n", l);
    if (l)
    {
        while (l != NULL)
        {
            printf("l'array allocato e' %s\n", l);
            free(l);
            i++;
        }
        free(l);
    }
    return 0;
}
*/
