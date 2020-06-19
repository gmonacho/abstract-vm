#ifndef VM_H_
# define VM_H_
# include <stack>
# include <string>
# include "IOperand.h"

class Vm
{

private:
	std::stack<IOperand> stack;
	const IOperand* 	(*createOp[5])(std::string cons, int);

	const IOperand* 	createInt8(const std::string& value) const;
	const IOperand* 	createInt16(const std::string& value) const;
	const IOperand* 	createInt32(const std::string& value) const;
	const IOperand* 	createFloat(const std::string& value) const;
	const IOperand* 	createDouble(const std::string& value) const;

public:
	Vm();

	const IOperand* 	createOperand(
								eOperandType type,
								const std::string& value);
	
	virtual				~Vm() = default;
};

#endif