/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:01:03 by lottavi           #+#    #+#             */
/*   Updated: 2023/03/30 13:38:41 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_string(unsigned int value, int *strlen)
{
	int				i;
	unsigned int	temp;
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
/*questa funzione alloca dinamicamente una stringa di caratteri di dimensione
necessaria per contenere il valore in input in esadecimale. Inoltre, restituisce
la dimensione della stringa tramite il puntatore a strlen.
i e temp vengono inizializzati rispettivamente a 0 e al valore in input.
Si esegue un ciclo while che divide ripetutamente temp per 16 (base dell'esadecimale)
finché non si arriva al valore 0. In questo modo, si conta il numero di cifre necessarie
per rappresentare il valore in input in esadecimale. Si alloca dinamicamente una
stringa di caratteri di dimensione i + 1 (in quanto si deve considerare anche
il terminatore di stringa '\0'). Si assegna il valore i - 1 al puntatore strlen.
Si restituisce la stringa allocata*/

int	print_hex(unsigned int value, int asc)
{
	unsigned int	tempval;
	char			*printout;
	int				i;
	int				*iptr;

	iptr = &i;
	tempval = value;
	printout = create_string(value, iptr);
	if (!printout)
		return (0);
	while (tempval != 0)
	{
		if ((tempval % 16) < 10)
			printout[i] = (tempval % 16) + 48;
		else
			printout[i] = (tempval % 16) + asc;
		tempval = tempval / 16;
		i--;
	}
	ft_putstr_fd(printout, 1);
	i = ft_strlen(printout);
	free(printout);
	if (value == 0)
		i += print_char('0');
	return (i);
}
/*questa funzione converte il valore in input in esadecimale e lo stampa sullo standard output.
tempval e printout vengono inizializzati rispettivamente al valore in input e alla stringa allocata dalla funzione create_string().
Si controlla se la chiamata alla funzione create_string() ha avuto successo. In caso contrario, si restituisce 0.
Si esegue un ciclo while che divide ripetutamente tempval per 16 e inserisce il corrispondente carattere
esadecimale nella stringa printout. Se la cifra corrispondente è minore di 10, viene sommato il valore ASCII
del carattere '0', altrimenti viene sommato asc. Infine, tempval viene diviso per 16 e i viene decrementato.
Si stampa la stringa printout sullo standard output con la funzione ft_putstr_fd().
Si assegna la lunghezza della stringa printout alla variabile i.
Si dealloca la memoria della stringa printout.
Se il valore in input è zero, si stampa il carattere '0' e si incrementa i.
Si restituisce i, ovvero la lunghezza della stringa stampata sullo standard output.*/
