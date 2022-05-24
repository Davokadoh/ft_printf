/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:06:36 by jleroux           #+#    #+#             */
/*   Updated: 2022/05/03 10:54:40 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	remove_neg(long int nbr)
{
	unsigned int	u_nbr;

	if (nbr < 0 && nbr >= -2147483648)
		u_nbr = -nbr;
	else
		u_nbr = nbr;
	return (u_nbr);
}

static void	calculate_lengths(t_flags *flags, int len, int nbr)
{
	int	sign;

	if (flags->plus || flags->space || nbr < 0)
		sign = 1;
	else
		sign = 0;
	flags->precision -= len;
	if (flags->precision < 0)
		flags->precision = 0;
	flags->width -= len + flags->precision + sign;
}

static int	print_left(t_flags *flags, int nbr)
{
	int	len;

	len = 0;
	while (flags->padding_char != '0' && flags->precision > 0 && !flags->right_padded)
		len += write(1, " ", flags->precision--);
	if (nbr < 0)
		len += write(1, "-", 1);
	else if (flags->plus)
		len += write(1, "+", 1);
	else if (flags->space)
		len += write(1, " ", 1);
	return (len);
}

static int	print_zeroes(t_flags *flags)
{
	int	i;

	if (flags->padding_char == '0' && !flags->precision && !flags->right_padded && flags->width > 0)
	{
		i = 0;
		while (--flags->width > 0)
			i += write(1, "0", 1);
		return (i);
	}
	else if (flags->precision > 0)
	{
		i = 0;
		while (--flags->precision > 0)
			i += write(1, "0", 1);
		return (i);
	}
	else
		return (0);
}

static int	print_right(t_flags *flags)
{
	int i;

	i = 0;
	if (flags->right_padded)
	{
		while (flags->width-- > 0)
			i += write(1, " ", 1);
	}
	return (i);
}

int	put_nbr(long long int nbr, t_flags *flags)
{
	long long unsigned int	u_nbr;
	char			*int_str;
	int				len;
	int				total;

	u_nbr = remove_neg(nbr);
	int_str = ft_itoa(u_nbr);
	len = ft_strlen(int_str);
	total = len;
	calculate_lengths(flags, len, nbr);
	total += print_left(flags, nbr);
	total += print_zeroes(flags);
	write(1, int_str, len);
	free(int_str);
	total += print_right(flags);
	return (total);
}
