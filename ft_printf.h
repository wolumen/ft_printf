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
# include <stdarg.h>

typedef struct s_print
{ 
	va_list	args;		// arg to print out
	int	zero;			//zero padding
	int	wdt;			//width
	int	pnt;			//.
	int	prc;			//precision
	int	dash;			//-		
	int	tl;				//total_length(returnvalue)	
	int	sign;			//pos or neg number
	int	is_zero;		//is number zero
	int	perc;			//%
	int	sp;				//space flag ' '				
}	t_print;

#endif