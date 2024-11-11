/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:10:09 by azahajur          #+#    #+#             */
/*   Updated: 2023/07/23 16:49:29 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, char p)
{
	int	cnt;

	cnt = 0;
	if (n >= 16)
	{
		cnt += ft_putnbr_hex(n / 16, p);
		cnt += ft_putnbr_hex(n % 16, p);
	}
	else if (p == 'x')
	{
		write(1, &"0123456789abcdef"[n % 16], 1);
		cnt++;
	}
	else if (p == 'X')
	{
		write(1, &"0123456789ABCDEF"[n % 16], 1);
		cnt++;
	}
	return (cnt);
}
