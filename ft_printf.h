/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzcarv <bluzcarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:48:56 by bluzcarv          #+#    #+#             */
/*   Updated: 2021/10/31 12:30:24 by bluzcarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_putnbr(int nb);
int		ft_print_u(unsigned int n);
char	ft_check_format(char c, va_list args);
int		ft_print_p(void *pointer);
int		ft_print_hexa_x_upper(size_t nbr);
int		ft_print_hexa_x(size_t nbr);
#endif
