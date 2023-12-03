/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanus <chanus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:20:11 by chanus            #+#    #+#             */
/*   Updated: 2023/12/02 13:21:36 by chanus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IS_NUMERIC
#define FT_IS_NUMERIC
int	ft_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
#endif