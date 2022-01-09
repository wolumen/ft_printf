/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:16:35 by jpreissn          #+#    #+#             */
/*   Updated: 2022/01/05 10:16:35 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, const char format)				// format is entweder x oder X
{
	char	hexstr[2 * sizeof(size_t) + 1];
	int		i;
	int		j;
	int		temp;

	if (num == 0)
		return (write(1, "0", 1));
	i = 0;
	j = 0;
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			hexstr[i] = temp + '0';
		else if (format == 'x')
			hexstr[i] = (temp - 10) + 'a';
		else if (format == 'X')
			hexstr[i] = (temp - 10) + 'A';
		i++;
		num = num / 16;
	}
	j = i - 1;
	while (j >= 0)
		ft_putchar(hexstr[j--]);
	return (i);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
