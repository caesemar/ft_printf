/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caesemar <caesemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:00:42 by jocasado          #+#    #+#             */
/*   Updated: 2022/10/12 15:48:45 by caesemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

size_t	ft_putstr(char *str);
size_t	ft_putchar(char c);
size_t	ft_put_u_nbr(unsigned int n, size_t *i);
size_t	ft_putnbr(int n, size_t *i);
size_t	ft_putnbr_hex(unsigned int nbr, size_t *i, char *base);
size_t	ft_p(unsigned long long nbr, size_t *i, char *base);
int		ft_printf(char const *str, ...);
size_t	flag_type(va_list args, char const str);
size_t	ft_put_p(unsigned long long nbr, size_t *i, char *base);

#endif