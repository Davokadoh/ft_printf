/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:56:23 by jleroux           #+#    #+#             */
/*   Updated: 2022/05/24 14:58:28 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(char *nbr_str, t_flags *flags)
{
	int	c;

	c = ft_strlen(nbr_str);
	if (flags->precision == 0 && *nbr_str == '0')
		return (0);
	if (flags->precision > c)
		c = flags->precision;
	else if (flags->precision < 0 && flags->padding_char == '0' && c < flags->width)
		return (flags->width);
	if (*nbr_str == '-' && (c == flags->precision))
		c++;
	else if (*nbr_str != '-' && (flags->plus || flags->space))
		c++;
	return (c);
}

static void	print_int_precision(int nbr, char *nbr_str, t_flags *flags)
{
	int	count;

	if (nbr < 0)
		put_char(nbr_str++[0]);
	else if (flags->plus)
		put_char('+');
	else if (flags->space)
		put_char(' ');
	if (flags->precision == 0 && *nbr_str == '0')
		return ;
	count = ft_strlen(nbr_str);
	while (count < flags->precision)
		count += put_char('0');
	if (nbr < 0 || flags->plus || flags->space)
		count++;
	while (flags->padding_char == '0' && count < flags->width)
		count += put_char('0');
	put_str(nbr_str, flags);
}

int	put_int(long long int nbr, t_flags *flags)
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
		print_int_precision(nbr, nbr_str, flags);
	while (count < flags->precision)
		count += put_char(' ');
	if (!flags->right_padded)
		print_int_precision(nbr, nbr_str, flags);
	free(nbr_str);
	return (count);
}