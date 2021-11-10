/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzcarv <bluzcarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:47:07 by bluzcarv          #+#    #+#             */
/*   Updated: 2021/11/08 10:21:23 by bluzcarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	size_t		i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		i++;
	}
	write(1, str, i);
	return (i);
}

	/* Returns a pointer to the first occurrence of character in the C string
	 * str. The terminating null-character is considered part of the C string.
	 * Therefore, it can also be located in order to retrieve a pointer to the
	 * end of a string.*/
char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)s + i);
	return (NULL);
}

	/* This function will display the integer n on the standard output. We will
	 * be breaking down int number as a whole into individual single digit
	 * numbers and we will convert those int numbers into characters that we
	 * will display on the standard output using our ft_putchar function. If
	 * the number is negative we immediately use ft_putchar('-') to display the
	 * minus sign to the standard output. We then multiply nbr by -1 to create
	 * a negative version of the variable n, making it a positive number and we
	 * continue to the next if. Then, ot checks if the number is greater than
	 * or equal to 10. If it is we begin to break down the number recursively
	 * to each individual digit, where we will then convert it into a
	 * character. The division by 10 will take us further into the recursion
	 * until we finally reach the very first number in our int. If you look at
	 * the modulus 10 we use a + '0' to convert the number into a char value.
	 * Though this seems like it will be put to the standard output
	 * immediately, it will actually happen last since it will be the last
	 * thing to happen when we backtrack out of our recursion. We will use
	 * ft_putchar on this digit to display it on the standard output and then
	 * back track through our recursion until every individual digit has been
	 * displayed.*/
int	ft_putnbr(int nb)
{
	unsigned int	nbr;
	int				quantchar;

	quantchar = 0;
	if (nb < 0)
	{
		quantchar += ft_putchar('-');
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		quantchar += ft_putnbr(nbr / 10);
	quantchar += ft_putchar((char)(nbr % 10 + '0'));
	return (quantchar);
}
