/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:06:26 by jleroux           #+#    #+#             */
/*   Updated: 2022/05/24 14:17:16 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(long long int nbr, t_flags *flags, char min_maj)
{
	char	*base;
	char	*str;
	int		count;

	count = 0;
	if (min_maj == 'x')
		base = "0123456789abcdef";
	if (min_maj == 'X')
		base = "0123456789ABCDEF";
	if (flags->hash == 1)
		count += write(1, "0x", 2);
	str = ft_itoa_base(nbr, base);
	
	count = get_width();
	if (aligned)
		print_precision();
	while (count < flags->width)
		count += put_char(' ');
	if (!aligned)
		print_precision();


	count += write(1, str, ft_strlen(str));
	free(str);
	return (count);
}
