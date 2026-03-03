/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:29:11 by gifanell          #+#    #+#             */
/*   Updated: 2025/01/20 17:21:33 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uputnbr(unsigned int nb)
{
	char	c;
	int		i;

	i = 0;
	if (nb > 9)
	{
		i += ft_uputnbr(nb / 10);
		i += ft_uputnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		i += write(1, &c, 1);
	}
	return (i);
}
