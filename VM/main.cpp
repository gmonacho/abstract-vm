/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:17:13 by gal               #+#    #+#             */
/*   Updated: 2020/06/19 17:01:35 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Operand.h"

int	main()
{
	std::cout << "Abstract-Vm !" << std::endl;

	Operand<int32_t>		op1(21);
	Operand<int32_t>		op2(0);

	auto				op3 = op1 / op2;

	std::cout
			<< "la"
			<< std::endl;
	std::cout
			<< "op3 = "
			<< op3->toString()
			<< std::endl;
	return (0);
}
