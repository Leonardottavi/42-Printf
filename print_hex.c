/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:01:03 by lottavi           #+#    #+#             */
/*   Updated: 2023/05/10 16:49:14 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_upcase(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (nbr > 15)
	{
		print_upcase(nbr / 16);
		print_upcase(nbr % 16);
	}
	else if (nbr > 9)
	{
		ft_putchar(nbr - 10 + 'A');
	}
	if (nbr <= 9)
	{
		ft_putchar(nbr + 48);
	}
	i += ft_count16(nbr);
	return (i);
}

int	print_lowcase(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (nbr > 15)
	{
		print_lowcase(nbr / 16);
		print_lowcase(nbr % 16);
	}
	else if (nbr > 9)
	{
		ft_putchar (nbr - 10 + 'a');
	}
	if (nbr <= 9)
	{
		ft_putchar (nbr + 48);
	}
	i += ft_count16(nbr);
	return (i);
}

int	ft_count16(unsigned long long ptr)
{
	int	i;

	i = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}
