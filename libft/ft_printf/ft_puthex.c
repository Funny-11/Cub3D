/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:41:48 by gifanell          #+#    #+#             */
/*   Updated: 2025/01/20 17:21:33 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long n, bool is_lower)
{
	char	offset;
	int		count;
	char	c;

	count = 0;
	offset = 'A';
	if (is_lower)
		offset = 'a';
	if (n == 0)
		count += write(1, "0", 1);
	else if (n > 0 && n < 16)
	{
		if (n < 10)
			c = n + '0';
		else
			c = (n - 10) + offset;
		write(1, &c, 1);
		count++;
	}
	else
	{
		count += ft_puthex(n / 16, is_lower);
		count += ft_puthex(n % 16, is_lower);
	}
	return (count);
}
/*
int	main(void)
{
 	int		a = 255;
 	int b;
	
 	printf("esad reale: %x\n", a);
 	b = ft_puthex(a, false);
 	printf("\n%d", b);
 	
 	
}
*/
