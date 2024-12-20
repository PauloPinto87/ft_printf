/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:54:05 by paulo             #+#    #+#             */
/*   Updated: 2024/12/20 13:23:45 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_dec_hex(char c, unsigned long num, int *count_char)
{
	char	*list_hex;

	if (!num)
	{
		ft_putstr_fd("(nill)", 1);
		*count_char += 3;
		return ;
	}
	(*count_char)++;
	if (c == 'X')
		list_hex = "0123456789ABCDEF";
	else
		list_hex = "0123456789abcdef";
	if (num >= 16)
		conv_dec_hex(c, num / 16, count_char);
	ft_putchar_fd(list_hex[num % 16], 1);
}

static int	write_char_str_int(char c, va_list ap, int count_char)
{
	char	*str;
	int		num;

	if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
	{
		str = va_arg(ap, char *);
		if (!va_arg(ap, char *))
			str = "(null)";
		ft_putstr_fd(str, 1);
		count_char += ft_strlen(str) - 1;
	}
	else if (c == 'd' || c == 'i')
	{
		num = va_arg(ap, int);
		ft_putnbr_fd(num, 1);
		while (num / 10 != 0)
		{
			num /= 10;
			count_char++;
		}
		count_char++;
	}
	return (++count_char);
}

static void	put_un_int(unsigned int num, int *count_char)
{
	(*count_char)++;
	if (num >= 10)
		put_un_int(num / 10, count_char);
	ft_putnbr_fd(num % 10, 1);
}

static int	verify_percent(char c, int count_char, va_list ap)
{
	unsigned long	pnt;

	if (c == 'c' || c == 's' || c == 'd' || c == 'i')
		count_char = write_char_str_int(c, ap, count_char);
	else if (c == 'p')
	{
		pnt = va_arg(ap, unsigned long);
		if (pnt != 0)
			ft_putstr_fd("0x", 1);
		count_char += 2;
		conv_dec_hex(c, pnt, &count_char);
	}
	else if (c == 'u')
		put_un_int(va_arg(ap, unsigned int), &count_char);
	else if (c == 'x' || c == 'X')
		conv_dec_hex(c, va_arg(ap, unsigned int), &count_char);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
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
			ft_putchar_fd(format[i], 1);
			i++;
			count_char++;
		}
	}
	va_end(ap);
	return (count_char);
}
