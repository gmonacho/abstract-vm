/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:17:21 by gal               #+#    #+#             */
/*   Updated: 2020/06/18 20:17:21 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Vm.h"

Vm::Vm()
{
	this->createOp = {
		&this->createInt8,
		&this->createInt16,
		&this->createInt32,
		&this->createFloat,
		&this->createDouble
	}
}

const IOperand*	Vm::createOperand(
							eOperandType type,
							const std::string& value)
{
	return (this->createOp[type]);
}
