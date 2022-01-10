/* ************************************************************************** */
/*		                        */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:03:01 by jpreissn          #+#    #+#             */
/*   Updated: 2021/12/14 13:03:01 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>			// für die variadic fctn
# include <unistd.h>			// für write
# include <stdlib.h>			// für malloc und free

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long ptr);
int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_percent(void);
void	ft_putstr(char *str);
char	*ft_uitoa(unsigned int n);
void	ft_putchar(char c);
char	*ft_itoa(int n);

#endif