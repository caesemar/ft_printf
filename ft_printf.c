/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:02:56 by jocasado          #+#    #+#             */
/*   Updated: 2022/10/08 20:47:57 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

// • %c Imprime un solo carácter.
// • %s Imprime una string (como se define por defecto en C).
// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.
// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.
// • %u Imprime un número decimal (base 10) sin signo.
// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.
// • % % para imprimir el símbolo del porcentaje.

int	flag_type(va_list args, char const *str)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(args, char)));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*str == 'p')
	
	else if (*str == 'd')

	else if(*str == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if(*str == 'u')
		return (ft_put_u_nbr(va_arg(args, unsigned int)));
	else if (*str == 'x')

	else if (*str == 'X')
		
	else if (*str == '%')
		return (ft_putchar('%'));
	return (0);
}

int ft_printf(char const *str, ...)
{
	int		printed_len;
	va_list	args;
	int		i;

	va_start(args, i);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printed_len += flag_type(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			printed_len++;
		}
		i++;
	}
	va_end(args);
	return (printed_len);
}