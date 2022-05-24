/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:08:08 by jleroux           #+#    #+#             */
/*   Updated: 2022/04/26 16:13:27 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_u_nbr(unsigned int nbr)
{
	char	*integer;
	int		len;

	//if (nbr < 0)
	//	nbr = 2147483647 - nbr;
	integer = ft_itoa(nbr);
	len = write(1, integer, ft_strlen(integer));
	free(integer);
	return (len);
}
