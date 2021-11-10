/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzcarv <bluzcarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:37:23 by bluzcarv          #+#    #+#             */
/*   Updated: 2021/10/31 12:31:50 by bluzcarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	/* This function converts numbers to hexadecimal (base 16) in lowercase.*/
int	ft_print_hexa_x(size_t nbr)
{
	char	*base;
	int		result;

	base = "0123456789abcdef";
	result = 0;
	if (nbr >= 16)
		result = result + ft_print_hexa_x(nbr / 16);
	result = result + ft_putchar(base[nbr % 16]);
	return (result);
}

	/* This function converts numbers to hexadecimal (base 16) in uppercase.*/
int	ft_print_hexa_x_upper(size_t nbr)
{
	char	*base;
	int		result;

	base = "0123456789ABCDEF";
	result = 0;
	if (nbr >= 16)
		result = result + ft_print_hexa_x_upper(nbr / 16);
	result = result + ft_putchar(base[nbr % 16]);
	return (result);
}
