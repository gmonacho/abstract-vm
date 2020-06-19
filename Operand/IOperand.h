/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:17:18 by gal               #+#    #+#             */
/*   Updated: 2020/06/19 16:59:34 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_H_
# define IOPERAND_H_
# include <string>

enum eOperandType { Int8 = 0, Int16 = 1, Int32 = 2, Float = 3, Double = 4 };

class IOperand
{

public:
	virtual int 				getPrecision() const = 0;
	virtual eOperandType 		getType() const = 0;
	virtual const IOperand* 	operator+(const IOperand& rhs) const = 0;
	virtual const IOperand* 	operator-(const IOperand& rhs) const = 0;
	virtual const IOperand* 	operator*(const IOperand& rhs) const = 0;
	virtual const IOperand* 	operator/(const IOperand& rhs) const = 0;
	virtual const IOperand* 	operator%(const IOperand& rhs) const = 0;
	
	virtual const std::string&	toString() const = 0;
	
	virtual 					~IOperand() = default;

};

#endif
