/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:54:27 by lottavi           #+#    #+#             */
/*   Updated: 2023/03/30 13:29:53 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char *input, void *arg)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += print_char((int)arg);
	else if (*input == 's')
		i += print_string((char *)arg);
	else if (*input == 'p')
		i += print_pointer((unsigned long)arg, 87);
	else if (*input == 'd')
		i += print_int((int)arg);
	else if (*input == 'i')
		i += print_int((int)arg);
	else if (*input == 'u')
		i += print_unsigned((unsigned int)arg);
	else if (*input == 'x')
		i += print_hex((unsigned int)arg, 87);
	else if (*input == 'X')
		i += print_hex((unsigned int)arg, 55);
	return (i);
}
/*
Questa è una funzione statica check_type che riceve una stringa input e un puntatore arg.
La funzione controlla il primo carattere della stringa input e chiama la funzione di
stampa corrispondente, passando il valore arg. La funzione restituisce il numero di caratteri stampati.
*/

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				i += check_type(input, va_arg(args, void *));
			else if (*input == '%')
				i += print_char('%');
		}
		else
			i = i + print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}
/*
Questa è la funzione principale ft_printf che stampa una stringa di formato
input e gli eventuali argomenti args che vengono passati alla funzione.
La funzione utilizza un ciclo while per iterare attraverso la stringa di
formato input. Se il carattere corrente è %, la funzione chiama check_type
per stampare l'argomento corrispondente. Se invece il carattere corrente
non è %, la funzione stampa direttamente il carattere. La funzione restituisce
il numero totale di caratteri stampati.
*/
