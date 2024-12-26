/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:06:48 by paulo             #+#    #+#             */
/*   Updated: 2024/12/26 18:30:19 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int			is_negative;
	int			len;
	long int	c_long;
	char		temp_buff[12];

	c_long = (long int)n;
	is_negative = 0;
	if (c_long < 0)
	{
		is_negative = 1;
		c_long = -c_long;
	}
	len = count_digits(c_long) + is_negative;
	if (is_negative)
		temp_buff[0] = '-';
	temp_buff[len--] = '\0';
	while ((is_negative == 1 && len > 0) || (is_negative == 0 && len >= 0))
	{
		temp_buff[len--] = (c_long % 10) + '0';
		c_long = c_long / 10;
	}
	len = count_digits(n) + is_negative;
	write(1, temp_buff, len);
	return (len);
}
