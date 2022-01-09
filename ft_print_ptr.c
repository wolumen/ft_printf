/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:20:20 by jpreissn          #+#    #+#             */
/*   Updated: 2022/01/05 10:20:20 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long ptr)
{
	char hexadecimalNumber[2 * sizeof(size_t) + 1];
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	i += write(1, "0x", 2);									// write returns int
	if (ptr == 0)											// 0 ? NULL ? !ptr ?  ???
		return (i + write(1, "0", 1));
	while (ptr != 0)
	{
		temp = ptr % 16;
		if (temp < 10)
			*(hexadecimalNumber + j++) = temp + '0';
		else 
			*(hexadecimalNumber + j++) = (temp - 10) + 'a';
		i++;
		ptr = ptr / 16;
	}
	while (j > 0)										// don't forget the initial '0x' which raises i by 2 !!!
		ft_putchar(*(hexadecimalNumber + --j));
	return (i);
}
