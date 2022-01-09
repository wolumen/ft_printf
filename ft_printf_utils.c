/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:58:30 by jpreissn          #+#    #+#             */
/*   Updated: 2022/01/03 15:58:30 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);						// STEFFEN warum % rot? müssen es nicht '%' sein?
	return (1);
}

int	ft_printnbr(int n)
{
	int		print_length;
	char	*str;

	print_length = 0;
	str = ft_itoa(n);
	print_length = ft_printstr(str);
	free(str);								// in itoa allokalisiert
	return (print_length);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}
