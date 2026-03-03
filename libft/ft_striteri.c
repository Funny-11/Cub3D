/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:22 by gifanell          #+#    #+#             */
/*   Updated: 2024/12/08 19:48:29 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void    ft_test(unsigned int c, char *s)
{
    int	l;
    
    l = c % 2;
    if (l == 0)
        *s = *s - 32;
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/* DESCRIPTION
	/ENG/
	Parameters:
	s: The string on which to iterate.
	f: The function to apply to each character.
	ft_striteri apply a function to each character of a string
	(index specified)
	/ITA/
	La differenza tra ft_striteri e ft_strmapi è che ft_striteri non
	restituisce nulla e lavora direttamente sulla stringa originale.
	Questa funzione accetta due parametri, il primo è una stringa e
	il secondo è una funzione.
	Quello che fa ft_striteri è applicare la funzione f ad ogni carattere
	della stringa s.
	Passa l'indice del carattere nella stringa e un puntatore al carattere
	alla funzione f. La funzione f modifica direttamente il valore del
	carattere nella stringa originale.
   CHANGE_LOG
   	CAMBIAMENTO APPORTATO E PERCHE'
   RETURN VALUE
	Alla fine non dobbiamo restituire nulla ma la stringa originale
	sarà stata modificata.
----------------------------------------------------------------------------
*/
/*
int	main(void)
{
	char	s[] = "mangiaglitteracolazioneesplendituttoilgiorno";

	ft_striteri(s, ft_test);
	printf("%s\n", s);
	return (0);
}
*/
