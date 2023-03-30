/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:04:28 by lottavi           #+#    #+#             */
/*   Updated: 2023/03/30 13:48:56 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printout(unsigned int nb)
{
	if (nb > 9)
		print_unsigned(nb / 10);
	if (nb <= 9)
	{
		ft_putchar_fd(nb + 48, 1);
		return ;
	}
	ft_putchar_fd((nb % 10) + 48, 1);
}

int	print_unsigned(unsigned int nb)
{
	unsigned int	i;

	printout(nb);
	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

/*La funzione print_unsigned prende in input un intero non negativo e stampa il suo valore su standard output. La funzione richiama la funzione printout che effettua la stampa del numero convertendolo in una sequenza di caratteri ASCII.
La funzione printout effettua la conversione dell'intero passato in una sequenza di caratteri ASCII, dividendolo per 10 e stampando il resto finché il risultato della divisione non diventa minore o uguale a 9. Questo metodo permette di scrivere la sequenza di caratteri nel verso corretto.
Ad esempio, se viene passato alla funzione print_unsigned il valore 1234, la funzione printout effettua la divisione per 10, il resto è 4 e viene stampato. Quindi 123 diviso per 10 dà 12, con resto 3, che viene stampato. Successivamente si passa a 12 diviso per 10 che dà 1 e viene stampato. Infine, dato che 1 è minore di 10, viene semplicemente stampato.
In questo modo, la funzione print_unsigned stampa correttamente l'intero non negativo passato come parametro. La funzione restituisce il numero di cifre dell'intero.*/
