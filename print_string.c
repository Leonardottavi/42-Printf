/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:03:41 by lottavi           #+#    #+#             */
/*   Updated: 2023/03/30 13:46:04 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (s[i])
		i++;
	ft_putstr_fd(s, 1);
	return (i);
}
/*Viene dichiarata la funzione print_string con parametro s, che rappresenta la stringa da stampare.
Viene inizializzata la variabile i a 0. Questa variabile viene utilizzata per contare la lunghezza della stringa.
Viene effettuato un controllo: se la stringa passata come parametro è nulla (ossia s ha il valore NULL), viene stampata la stringa "(null)" utilizzando ft_putstr_fd e viene restituito 6, che è la lunghezza di "(null)".
Viene eseguita una iterazione sulla stringa, contando il numero di caratteri fino al terminatore di stringa '\0'.
Viene stampata la stringa utilizzando ft_putstr_fd.
Viene restituito il numero di caratteri stampati, ossia i.*/
