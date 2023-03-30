/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:03:02 by lottavi           #+#    #+#             */
/*   Updated: 2023/03/30 13:44:42 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_string(unsigned long value, int *strlen)
{
	int				i;
	unsigned long	temp;
	char			*str;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}
/*La funzione create_string alloca la memoria necessaria per la stringa esadecimale e calcola la sua lunghezza, in base al valore passato come parametro. Viene utilizzata per creare la stringa esadecimale corrispondente al puntatore.*/

int	print_pointer(unsigned long value, int asc)
{
	unsigned long	tempval;
	char			*printout;
	int				i;
	int				*iptr;

	iptr = &i;
	tempval = value;
	printout = create_string(value, iptr);
	if (!printout)
		return (0);
	while (tempval != 0 && i-- >= 0)
	{
		if ((tempval % 16) < 10)
			printout[i + 1] = (tempval % 16) + 48;
		else
			printout[i + 1] = (tempval % 16) + asc;
		tempval = tempval / 16;
	}
	i = ft_strlen(printout);
	i = i + print_string("0x");
	ft_putstr_fd(printout, 1);
	free(printout);
	if (value == 0)
		i += print_char('0');
	return (i);
}
/*La funzione print_pointer prende il valore del puntatore come parametro e lo salva in una variabile temporanea tempval. Inizializza una variabile printout utilizzando la funzione create_string, passando il valore del puntatore e un puntatore all'intero i.
Successivamente, viene eseguito un ciclo while, dove si dividono continuamente i valori di tempval per 16, e si assegna il risultato corrispondente al carattere esadecimale corretto in base al valore della variabile asc. Questo carattere esadecimale viene poi assegnato alla posizione giusta nella stringa printout.
Infine, viene stampata la stringa printout, insieme alla stringa "0x" per indicare che si tratta di un valore esadecimale, e viene liberata la memoria allocata per printout. Se il valore del puntatore è zero, viene stampato anche un carattere '0' e viene incrementata la lunghezza di ritorno i.*/
