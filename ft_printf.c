/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:08:32 by caesemar          #+#    #+#             */
/*   Updated: 2022/10/11 17:46:20 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

// • %c Imprime un solo carácter.
// • %s Imprime una string (como se define por defecto en C).
// • %p El puntero void  dado como argumento se imprime en formato hexadecimal.
// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.
// • %u Imprime un número decimal (base 10) sin signo.
// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.
// • % % para imprimir el símbolo del porcentaje.

size_t	flag_type(va_list args, char const str)
{
	size_t	i;

	i = 0;
	if (str == 'c')
		return (ft_putchar(va_arg(args, size_t)));
	else if (str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str == 'p')
		return (ft_p(va_arg(args, unsigned long long), &i, "0123456789abcdef"));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(args, size_t), &i));
	else if (str == 'u')
		return (ft_put_u_nbr(va_arg(args, int), &i));
	else if (str == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), &i, \
		"0123456789abcdef"));
	else if (str == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), &i, \
		"0123456789ABCDEF"));
	else if (str == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	size_t	printed_len;
	va_list	args;
	size_t	i;

	i = 0;
	printed_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printed_len += flag_type(args, str[i + 1]);
			i++;
		}
		else
			printed_len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return ((int) printed_len);
}
