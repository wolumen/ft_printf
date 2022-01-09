/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:11:20 by jpreissn          #+#    #+#             */
/*   Updated: 2022/01/09 14:11:20 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int	ft_len(int n);
static char		*ft_array(char *str, unsigned int number, long int len);

int	ft_printnbr(int n)
{
	int		print_length;
	char	*str;

	print_length = 0;
	str = ft_itoa(n);
	print_length = ft_printstr(str);
	free(str);
	return (print_length);
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
	str[len--] = '\0';
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

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
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
