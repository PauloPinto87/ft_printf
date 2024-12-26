/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:54:05 by paulo             #+#    #+#             */
/*   Updated: 2024/12/26 18:31:28 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_un_int(unsigned int num, int *count_char)
{
	(*count_char)++;
	if (num >= 10)
		put_un_int(num / 10, count_char);
	ft_putnbr(num % 10);
}

static int	verify_percent(char c, int count_char, va_list ap)
{
	if (c == 'c')
		count_char += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count_char += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count_char += ft_putnbr(va_arg(ap, int));
	else if (c == 'p')
		ft_puthex(c, va_arg(ap, unsigned long), &count_char);
	else if (c == 'u')
		put_un_int(va_arg(ap, unsigned int), &count_char);
	else if (c == 'x' || c == 'X')
		ft_puthex(c, va_arg(ap, unsigned int), &count_char);
	else if (c == '%')
	{
		write(1, "%%", 1);
		count_char++;
	}
	return (count_char);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count_char;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	count_char = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count_char = verify_percent(format[i + 1], count_char, ap);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			count_char++;
		}
	}
	va_end(ap);
	return (count_char);
}
