/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:22:13 by paulo             #+#    #+#             */
/*   Updated: 2024/12/21 14:22:16 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	x;

	x = 42;
	printf("Escola[%-10d]\n", x);
	
	/*
	printf("Return ft_printf = %d\n", ft_printf("ft_printf c = %c\n", 'a'));
	printf("Return printf    = %d\n", printf("printf c    = %c\n", 'a'));

	printf("\n");

	printf("Return ft_printf = %d\n", ft_printf("ft_printf str = %s\n", "Escola 42"));
	printf("Return printf    = %d\n", printf("printf str    = %s\n", "Escola 42"));
	
	printf("\n");

	printf("Return ft_printf = %d\n", ft_printf("ft_printf addres x = %p\n", &x));
	printf("Return printf    = %d\n", printf("printf addres x    = %p\n", &x));

	printf("\n");

	printf("Return ft_printf = %d\n", ft_printf("ft_printf porcentagem %%p\n"));
	printf("Return printf    = %d\n", printf("printf porcentagem    %%p\n"));
	
	printf("\n");

	printf("Return ft_printf = %d\n", ft_printf("ft_printf decimal %d\n", INT_MIN));
	printf("Return printf    = %d\n", printf("printf decimal    %d\n", INT_MIN));

	printf("\n");

	printf("Return ft_printf = %d\n", ft_printf("ft_printf inteiro %i\n", INT_MIN));
	printf("Return printf    = %d\n", printf("printf inteiro    %i\n", INT_MIN));

	printf("\n");

	printf("Return ft_printf = %d\n", ft_printf("ft_printf unsigned = %u\n", UINT_MAX));
	printf("Return printf    = %d\n", printf("printf unsigned    = %u\n", UINT_MAX));

	printf("\n");

	printf("Return ft_printf =   %d\n", ft_printf("ft_printf dec para hex lower = %x\n", 50224061));
	printf("Return printf    =   %d\n", printf("printf dec para hex lower    = %x\n", 50224061));

	printf("\n");

	printf("Return ft_printf =   %d\n", ft_printf("ft_printf dec para hex upper = %X\n", 50224061));
	printf("Return printf    =   %d\n", printf("printf dec para hex upper    = %X\n", 50224061));

	printf("\n");

	printf("Return ft_printf = %d\n", ft_printf("ft_printf adress NULL = %p\n", (void *)0));
	printf("Return printf    = %d\n", printf("printf  adress NULL   = %p\n", (void *)0));

	printf("\n");

	char *str_null = NULL;

	printf("Return ft_printf = %d\n", ft_printf("ft_printf str NULL = %s\n", str_null));
	printf("Return printf    = %d\n", printf("printf str    NULL = %s\n", str_null));
	*/
}