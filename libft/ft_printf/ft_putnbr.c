/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:41:08 by gifanell          #+#    #+#             */
/*   Updated: 2025/01/20 17:44:01 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	char	c;
	int		i;

	i = 0;
	c = '\0';
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		i += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	i += write(1, &c, 1);
	return (i);
}

/*
int	main(void)
{
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(-42);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	printf("\n%d\n", ft_putnbr(-2147483648));
	ft_putnbr(42);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
*/
