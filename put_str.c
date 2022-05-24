/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:50:21 by jleroux           #+#    #+#             */
/*   Updated: 2022/05/03 10:27:45 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *str, t_flags *flags)
{
	int	str_len;
	int	print_count;

	if (!str)
		return(put_str("(null)", flags));
	str_len = ft_strlen(str);
	if (flags->precision != -1 && flags->precision < str_len)
		str_len = flags->precision;
	print_count = str_len;
	if (flags->right_padded)
		write(1, str, str_len);
	while (print_count < flags->width)
		print_count += putchar(' ');
	if (!flags->right_padded)
		write(1, str, str_len);
	return (print_count);
}
