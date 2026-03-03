/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:58:08 by gifanell          #+#    #+#             */
/*   Updated: 2025/04/15 17:05:35 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_print_formats(va_list ap, const char specifier)
{
	int	res;

	res = 0;
	if (specifier == 'c')
		res += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		res += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		res += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'x' || specifier == 'X')
		res += ft_puthex(va_arg(ap, unsigned int), specifier == 'x');
	else if (specifier == 'u')
		res += ft_uputnbr(va_arg(ap, unsigned int));
	else if (specifier == 'p')
		res += ft_putptr(va_arg(ap, unsigned long));
	else if (specifier == '%')
		res += ft_putchar('%');
	return (res);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	ap;
	size_t	i;
	int		res;

	va_start(ap, format_str);
	i = 0;
	res = 0;
	if (!format_str)
		return (-1);
	while (format_str && format_str[i])
	{
		if (format_str[i] == '%')
		{
			res += ft_print_formats(ap, format_str[i + 1]);
			i++;
		}
		else
			res += ft_putchar(format_str[i]);
		i++;
	}
	va_end(ap);
	return (res);
}
