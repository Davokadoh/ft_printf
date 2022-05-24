/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:59:31 by jleroux           #+#    #+#             */
/*   Updated: 2022/05/24 14:59:33 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(char *nbr_str, t_flags *flags)
{
	int	count;

	count = ft_strlen(nbr_str);
	if (flags->precision == 0 && *nbr_str == '0')
		return (0);
	if (flags->precision > count)
		count = flags->precision;
	else if (flags->precision < 0 && flags->padding_char == '0' && count < flags->width)
		return (flags->width);
	else if (flags->plus || flags->space)
		count++;
	return (count);
}

static void	print_int_precision(char *nbr_str, t_flags *flags)
{
	int	count;

	if (flags->plus)
		putchar('+');
	else if (flags->space)
		putchar(' ');
	if (flags->precision == 0 && *nbr_str == '0')
		return ;
	count = ft_strlen(nbr_str);
	while (count < flags->precision)
		count += putchar('0');
	if (flags->plus || flags->space)
		count++;
	while (flags->padding_char == '0' && count < flags->width)
		count += putchar('0');
	put_str(nbr_str, flags);
}

int	put_u_int(unsigned int nbr, t_flags *flags)
{
	char	*nbr_str;
	int		count;

	nbr_str = ft_itoa(nbr);
	if (!nbr_str)
		return (-1);
	if (flags->precision >= 0 || flags->right_padded)
		flags->padding_char = ' ';
	count = get_width(nbr_str, flags);
	if (flags->right_padded)
		print_int_precision(nbr_str, flags);
	while (count < flags->precision)
		count += put_char(' ');
	if (!flags->right_padded)
		print_int_precision(nbr_str, flags);
	free(nbr_str);
	return (count);
}
