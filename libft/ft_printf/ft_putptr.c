/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:50:41 by gifanell          #+#    #+#             */
/*   Updated: 2025/01/20 17:21:33 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	else
	{
		count += write(1, "0x", 2);
		count += ft_puthex(ptr, true);
	}
	return (count);
}

/*  int	main(void)
{
	printf("%d\n", ft_putptr(255));
	printf("%d\n", ft_putptr(0));
	printf("\n%d\n%d", INT_MIN, ft_putptr(INT_MIN));
	return (0);
} */
