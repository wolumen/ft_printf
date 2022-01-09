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
	char	hexstr[2 * sizeof(unsigned long) + 1];
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = 0;
	i += write(1, "0x", 2);
	if (ptr == 0)											//  !ptr
		return (i + write(1, "0", 1));
	while (ptr != 0)
	{
		temp = ptr % 16;
		if (temp < 10)
			hexstr[j] = temp + '0';
		else
			hexstr[j] = (temp - 10) + 'a';
		j++;
		ptr = ptr / 16;
	}
	i += j;
	j--;
	while (j >= 0)
		ft_putchar(hexstr[j--]);
	return (i);
}
