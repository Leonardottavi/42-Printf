/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:02:25 by lottavi           #+#    #+#             */
/*   Updated: 2023/03/30 13:40:43 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	int				nb;
	unsigned int	i;

	nb = n;
	i = 1;
	if (n < 0 && n != -2147483648)
	{
		nb = -n;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	if (n == -2147483648)
		return (11);
	return (i);
}
/*La funzione print_int stampa un numero intero passato come parametro n sulla standard output e ritorna il numero di cifre del numero stampato.
Viene dichiarata una variabile nb inizializzata con il valore di n e una variabile i inizializzata a 1. La variabile nb è utilizzata per calcolare il numero di cifre del numero intero in input, mentre la variabile i è utilizzata per tenerne traccia.
Se n è negativo e diverso da -2147483648 (il valore minimo rappresentabile da un intero a 32 bit), si esegue una serie di operazioni per gestire la stampa del segno negativo.
Si cambia il segno di nb.
Si incrementa la variabile i di 1.
Si stampa il segno meno sulla standard output utilizzando la funzione ft_putchar_fd.
Viene eseguito un ciclo while per contare il numero di cifre di nb. Ad ogni iterazione si divide nb per 10 e si incrementa la variabile i di 1. Il ciclo termina quando nb diventa minore di 10.
Viene stampato il numero intero sulla standard output utilizzando la funzione ft_putnbr_fd.
Se n è uguale a -2147483648, la funzione ritorna 11 (il numero di cifre del valore assoluto del numero intero).
Altrimenti, la funzione ritorna il numero di cifre del numero intero stampato (ovvero il valore di i).*/
