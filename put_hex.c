/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:06:26 by jleroux           #+#    #+#             */
/*   Updated: 2022/05/24 15:14:15 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(char *str, t_flags *flags)
{
	int	c;

	c = ft_strlen(str);
	if (flags->precision == 0 && str[0] == '0')
		c = 0;
	if (flags->precision > c)
		c = flags->precision;
	if (flags->hash && str[0] != '0')
		c += 2;
	if (flags->precision == -1 && flags->precision == '0' && c < flags->width)
		return (flags->width);
	if (str[0] == '-' && (c == flags->precision || c == flags->width))
		c++;
	return (c);
}

static void	print_precision(char *str, t_flags *flags)
{
	int	count;

	if (flags->precision == 0 && str[0] == '0')
		return ;
	count = ft_strlen(str);
	if (flags->hash && str[0] != '0' && count)
		put_str("0X", flags);
	else if (flags->hash && str[0] != '0')
		put_str("0x", flags);
	while (count < flags->precision)
		count += put_char('0');
	if (flags->hash && str[0] != '0')
		count += 2;
	while (flags->padding_char == '0' && count < flags->width)
		count += put_char('0');
	put_str(str, flags);
}

int	put_hex(long long int nbr, t_flags *flags, char min_maj)
{
	char	*base;
	char	*str;
	int		count;

	count = 0;
	if (min_maj == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	str = ft_itoa_base(nbr, base);
	count = get_width(str, flags);
	if (flags->right_padded)
		print_precision(str, flags);
	while (count < flags->width)
		count += put_char(' ');
	if (!flags->right_padded)
		print_precision(str, flags);
	free(str);
	return (count);
}

int put_ptr(void *ptr, t_flags *flags)
{	
	char	*base;
	char	*str;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	flags->hash = 1;
	str = ft_u_itoa_base(nbr, base);
	count = get_width(str, flags);
	if (flags->right_padded)
		print_precision(str, flags);
	while (count < flags->width)
		count += put_char(' ');
	if (!flags->right_padded)
		print_precision(str, flags);
	free(str);
	return (count);
    return (write(1, "0x", 2) + put_hex((long long int) ptr, flags, 'x'));
}