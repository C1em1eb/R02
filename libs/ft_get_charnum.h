/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_charnum.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanus <chanus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:12:48 by chanus            #+#    #+#             */
/*   Updated: 2023/12/03 16:08:56 by chanus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	get_digits(int num)
{
	int i;

	i = 0; // added by clement
	while (num > 0)
	{
		num /= 10; // changed n to num by clement
		i++;
	}
	if (num == 0)
		i++;
	return (i);
}

char	*ft_get_charnum(int nb) //changed int to char by clement
{
	char *str_res;
    int i = 0;
    unsigned int ui;
    str_res = malloc(get_digits(nb) + 1);
    if (nb < 0) {
        write(1, "-", 1);
        ui = nb * -1;
    } else {
        ui = nb;
    }
    while (ui > 0) {
        str_res[i++] = '0' + (ui % 10);
        ui /= 10;
    }
    if (nb != 0) {
        str_res[i] = '\0'; // Null-terminate the string
    } else {
        str_res[0] = '0';
        str_res[1] = '\0';
    }
    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str_res[start];
        str_res[start] = str_res[end];
        str_res[end] = temp;
        start++;
        end--;
    }
    return str_res;
}

// put in comment by clement
/* int main()
{
	ft_putnbr(INT_MIN);
}
 */
