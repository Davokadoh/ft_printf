/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:01:03 by jleroux           #+#    #+#             */
/*   Updated: 2022/05/03 11:18:15 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc((ft_strlen(src) + 1) * sizeof(*src));
	if (!str)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*mystr;

	mystr = "test";
	printf("%s\n", mystr);
	printf("%s\n", ft_strdup(mystr));
}
*/
