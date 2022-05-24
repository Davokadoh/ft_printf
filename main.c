/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:52:58 by jleroux           #+#    #+#             */
/*   Updated: 2022/05/24 14:52:59 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.c"

int	main(void)
{
	printf(" %i\n", printf("[ %-2d]", -1));
	fflush(stdout);
	printf(" %i\n", ft_printf("[ %-2d]", -1));
	fflush(stdout);
}
