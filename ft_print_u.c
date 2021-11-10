/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzcarv <bluzcarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:54:21 by bluzcarv          #+#    #+#             */
/*   Updated: 2021/10/31 12:33:25 by bluzcarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	/* ft_put_u deals with flag %u, prints an unsigned decimal (base 10)
	 * number. This uses the same logic as 'ft_putnbr'.*/
int	ft_print_u(unsigned int n)
{
	int		ret;

	ret = 0;
	if (n >= 10)
	{
		ret = ret + ft_putnbr(n / 10);
	}
	ret = ret + ft_putchar((char)(n % 10 + '0'));
	return (ret);
}
