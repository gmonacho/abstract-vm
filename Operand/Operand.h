/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:17:15 by gal               #+#    #+#             */
/*   Updated: 2020/06/19 17:00:55 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_H_
# define OPERAND_H_
# include <type_traits>
# include <stdio.h>
# include <inttypes.h>
# include "IOperand.h"

template<typename T>
class Operand : public IOperand
{

private:
	T							value;
	eOperandType				type;
	std::string					strValue;
	const char*					scanfType[5];

public:
	Operand(const T& value);

	~Operand() = default;

	virtual int					getPrecision() const override;

	virtual eOperandType		getType() const override;

	virtual const IOperand*		operator+(const IOperand& rhs) const override;
	virtual const IOperand* 	operator-(const IOperand& rhs) const override;
	virtual const IOperand* 	operator*(const IOperand& rhs) const override;
	virtual const IOperand* 	operator/(const IOperand& rhs) const override;
	virtual const IOperand* 	operator%(const IOperand& rhs) const override;
	
	virtual std::string const & toString() const;

};

template<typename T>
Operand<T>::Operand(const T& value)
{
	this->value = value;
    if constexpr (std::is_same_v<T, int8_t>)
		this->type = Int8;
    else if constexpr (std::is_same_v<T, int16_t>)
		this->type = Int16;
    else if constexpr (std::is_same_v<T, int32_t>)
		this->type = Int32;
    else if constexpr (std::is_same_v<T, float>)
		this->type = Float;
    else if constexpr (std::is_same_v<T, double>)
		this->type = Double;
	this->strValue = std::to_string(this->value);
	this->scanfType[0] = "%hhd";
	this->scanfType[1] = "%hd";
	this->scanfType[2] = "%d";
	this->scanfType[3] = "%f";
	this->scanfType[4] = "%lf";
}

template<typename T>
int				Operand<T>::getPrecision() const
{
	return (sizeof(this->type));
}

template<typename T>
eOperandType	Operand<T>::getType() const
{
	return (this->type);
}

template<typename T>
const IOperand* Operand<T>::operator+(const IOperand& rhs) const
{	
	T					v1 = this->value;
	T					v2;

	sscanf(rhs.toString().c_str(), this->scanfType[this->type], &v2);
	return (new Operand<T>(v1 + v2));
}

template<typename T>
const IOperand* Operand<T>::operator-(const IOperand& rhs) const
{	
	T					v1 = this->value;
	T					v2;

	sscanf(rhs.toString().c_str(), this->scanfType[this->type], &v2);
	return (new Operand<T>(v1 - v2));
}

template<typename T>
const IOperand* Operand<T>::operator*(const IOperand& rhs) const
{	
	T					v1 = this->value;
	T					v2;

	sscanf(rhs.toString().c_str(), this->scanfType[this->type], &v2);
	return (new Operand<T>(v1 * v2));
}

template<typename T>
const IOperand* Operand<T>::operator/(const IOperand& rhs) const
{	
	T					v1 = this->value;
	T					v2;

	sscanf(rhs.toString().c_str(), this->scanfType[this->type], &v2);
	return (new Operand<T>(v1 / v2));
}

template<typename T>
const IOperand* Operand<T>::operator%(const IOperand& rhs) const
{	
	T					v1 = this->value;
	T					v2;

	sscanf(rhs.toString().c_str(), this->scanfType[this->type], &v2);
	return (new Operand<T>(v1 % v2));
}

template<typename T>
const std::string& Operand<T>::toString() const
{
	return (strValue);
}

#endif
