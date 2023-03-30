/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:00:22 by lottavi           #+#    #+#             */
/*   Updated: 2023/03/30 13:32:01 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
/*Questo codice definisce la funzione print_char, che prende in input un
carattere c e restituisce un intero che rappresenta il numero di caratteri
effettivamente stampati sullo standard output. La funzione utilizza la funzione
ft_putchar_fd per scrivere il carattere sul file descriptor 1 (cioè lo standard
output). Infine, la funzione restituisce 1 per indicare che ha stampato un
singolo carattere.*/
