/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanus <chanus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:14:14 by chanus            #+#    #+#             */
/*   Updated: 2023/12/02 17:30:29 by chanus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRLEN
#define FT_STRLEN
unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
#endif