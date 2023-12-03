/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsame.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanus <chanus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:27:28 by chanus            #+#    #+#             */
/*   Updated: 2023/12/02 14:51:47 by chanus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRSAME
#define FT_STRSAME

int	ft_strsame(char *s1, char *s2)
{
	unsigned int c;

	c = 0;
	while (s1[c] == s2[c])
	{
		if (s1[c] == '\0')
		{
			return (1);
		}
		c++;
	}
	return (0);
}
#endif
