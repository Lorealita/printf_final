/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:37:18 by azahajur          #+#    #+#             */
/*   Updated: 2023/07/23 18:40:28 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int				cnt;

	cnt = 0;
	if (n == -2147483648)
	{
		cnt += write(1, "-2", 2);
		cnt += write(1, "147483648", 9);
		return (cnt);
	}
	if (n < 0)
	{
		cnt += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		cnt += ft_putchar((n + '0'));
	}
	else
	{
		cnt += ft_putnbr(n / 10);
		cnt += ft_putnbr(n % 10);
	}
	return (cnt);
}
