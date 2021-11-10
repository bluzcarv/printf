/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzcarv <bluzcarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:28:23 by bluzcarv          #+#    #+#             */
/*   Updated: 2021/10/31 12:32:41 by bluzcarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	/* The %p format takes a void * and prints it in an implementation-defined
	 * format. Ps: some implementations of printf() print a '0x' in front of
	 * the pointer; others do not (and both are correct according to the C
	 * standard).*/
int	ft_print_p(void *pointer)
{
	int		result;

	result = 0;
	result = result + write(1, "0x", 2);
	result = result + ft_print_hexa_x((size_t)pointer);
	return (result);
}
