/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:07:33 by jpreissn          #+#    #+#             */
/*   Updated: 2021/12/14 13:07:33 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_length;

	va_start(args, str);
	i = 0;
	print_length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));						//STEFFEN return ist ein String, wie wird der + gerechnet und wann geprinted?
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

static char	*ft_array(char *str, unsigned int number, long int len)
{
	if (number == 0)
		str[0] = '0';
	while (number > 0)
	{
		str[len] = '0' + (number % 10);
		number = number / 10;
		len--;
	}
	return (str);
}

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)   		// STEFFEN was wenn n = 0, dann keine len zurück aber 0 ist doch len 1?
	{
		len++;
		n = n / 10;				// MERKEN : int rechnet nur mit ganzen Zahlen!
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*str;
	long int			len;
	unsigned int		number;

	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';							//STEFFEN erst 0 setzten, dann -1 auf len?
	if (n < 0)
	{
		number = n * -1;
		str[0] = '-';
	}
	else
		number = n;
	str = ft_array(str, number, len);
	return (str);
}
