#include "RPN.hpp"

RPN::RPN()
:operand("")
{
}

RPN::RPN(const RPN& copy)
:operand("")
{
	*this = copy;
}

RPN::RPN(std::string _operand)
:operand(_operand)
{
}

RPN&	RPN::operator=(const RPN& copy)
{
	if (this != &copy)
	{
		this->main_stack = copy.main_stack;
		this->operand = copy.operand;
	}
	return (*this);
}

RPN::~RPN()
{
}

void	RPN::setOperand(std::string _operand)
{
	this->operand = _operand;
}

void	RPN::calculate()
{
	char	element;
	size_t	space_pos;

	while (this->operand.size() > 0)
	{
		element = this->getElement();
		switch (this->checkElement(element))
		{
		case NUMBER:
			this->pushNumber(element);
			break;

		case OPERATOR:
			this->calculateStack(element);
			break;

		default:
			printError();
			break;
		}
		space_pos = this->operand.find(' ');
		if (space_pos != std::string::npos)
			this->setOperand(this->operand.substr(space_pos + 1));
		else
			this->operand.clear();
	}
	if (this->main_stack.size() != 1)
		printError();
	this->print();
}

void	RPN::print()
{
	std::cout << GRN << this->main_stack.top() << std::endl;
}

char	RPN::getElement()
{
	std::istringstream	stream_operand(this->operand);
	std::string			sub_operand;

	if (this->operand.size() >= 2)
		std::getline(stream_operand, sub_operand, ' ');
	else
		std::getline(stream_operand, sub_operand);
	if (sub_operand.size() != 1)
		printError();
	return (sub_operand[0]);
}

static char	isOperator(const char& element)
{
	if (element == '+' ||
		element == '-' ||
		element == '/' ||
		element == '*')
		return (element);
	return (0);
}

Element	RPN::checkElement(const char& element)
{
	if (isdigit(element))
		return (NUMBER);
	else if (isOperator(element))
		return (OPERATOR);
	return (NONE);
}

void	RPN::pushNumber(const char element)
{
	this->main_stack.push(element - '0');
}

void	RPN::calculateStack(const char& element)
{
	if (this->main_stack.size() < 1)
		printError();

	int	first_number, second_number, result;

	second_number = this->main_stack.top();
	this->main_stack.pop();
	first_number = this->main_stack.top();
	this->main_stack.pop();

	if (element == '+')
		result = first_number + second_number;
	else if (element == '-')
		result = first_number - second_number;
	else if (element == '/')
		result = first_number / second_number;
	else if (element == '*')
		result = first_number * second_number;

	this->main_stack.push(result);
}

void	printError()
{
	std::cerr << RED << "Error" << std::endl;
	exit(1);
}
