/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzcarv <bluzcarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:06 by bluzcarv          #+#    #+#             */
/*   Updated: 2021/10/31 17:05:46 by bluzcarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	/* ft_check_format will evaluate the received format. It has a if-else
	 * loop that will try-out all the "cspdiuxX%" types, and return (0).*/
char	ft_check_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg (args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_u(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_print_p(va_arg(args, void *)));
	if (c == 'x')
		return (ft_print_hexa_x(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_print_hexa_x_upper(va_arg(args, unsigned int)));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

	/* Value to return: length of the printed string (int). The function will
	 * start with a loop. As long as the string is not %, it will keep printing
	 * what is read. Once it encounters a %, it checks the type of variable
	 * to print(format[i + 1] because evaluation starts after the % character).
	 * If it is the case, ft_flags will return the appropriate type value to
	 * be printed. Else, it keeps printing what is read. This is a variadic
	 * function, we use <stdargs.c> lib to declare, initialise, move
	 * through and close a variadic function (va_list args, va_start(args,
	 * format), va_arg(args, *), va_end(args)).*/
int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	int			len_string;

	i = 0;
	len_string = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			len_string = len_string + ft_check_format(format[++i], args);
			i++;
		}
		else
		{
			len_string = len_string + ft_putchar(format[i]);
			i++;
		}
	}
	va_end (args);
	return (len_string);
}
