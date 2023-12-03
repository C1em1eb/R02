/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanus <chanus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:14:24 by chanus            #+#    #+#             */
/*   Updated: 2023/11/20 16:17:09 by chanus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/*int	main(void)
{
	char	src[100] = "AlfaBeta Gamma";
	char	dest[100];
	
	ft_strcpy(dest, src);
	int i = 0;
	while (dest[i] != 0)
	{
		write(1, &dest[i++], 1);
	}
}*/
