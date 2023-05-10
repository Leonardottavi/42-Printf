/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:52 by lottavi           #+#    #+#             */
/*   Updated: 2023/05/10 16:40:56 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *input, ...);
int		print_pointer(unsigned long long ptr);
int		print_unsigned(unsigned int nb);
int		print_string(char *s);
int		print_int(int n);
int		print_char(char c);
int		print_upcase(unsigned int nbr);
int		print_lowcase(unsigned int nbr);
int		ft_count16(unsigned long long ptr);

#endif
