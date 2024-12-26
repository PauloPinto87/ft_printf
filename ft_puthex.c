/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:20:26 by paulo             #+#    #+#             */
/*   Updated: 2024/12/26 15:07:13 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnull(char c, int *count_char)
{
	if (c == 'p')
	{
		write(1, "(nil)", 5);
		*count_char += 5;
	}
	else
	{
		write (1, "0", 1);
		*count_char += 1;
	}
}

void	ft_puthex(char c, unsigned long num, int *count_char)
{
	char	*list_hex;

	if (num == 0)
	{
		ft_putnull(c, count_char);
		return ;
	}
	if (c == 'X')
		list_hex = "0123456789ABCDEF";
	else
		list_hex = "0123456789abcdef";
	if (num >= 16)
		ft_puthex(c, num / 16, count_char);
	else if (c == 'p')
	{
		*count_char += 2;
		write(1, "0x", 2);
	}
	(*count_char)++;
	write(1, &list_hex[num % 16], 1);
}
