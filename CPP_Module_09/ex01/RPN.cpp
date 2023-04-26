#include "RPN.hpp"

RPN::RPN(void)
:expression("")
{
}

RPN::RPN(const RPN& copy)
:expression("")
{
	*this = copy;
}

RPN::RPN(std::string _expression)
:expression(_expression)
{
}

RPN&	RPN::operator=(const RPN& copy)
{
	if (this != &copy)
	{
		this->main_stack = copy.main_stack;
		this->expression = copy.expression;
	}
	return (*this);
}

RPN::~RPN(void)
{
}

void	RPN::setExpression(std::string _expression)
{
	this->expression = _expression;
}

void	RPN::calculate(void)
{
	size_t	index = 0;;
	char	element;

	while (index < this->expression.size())
	{
		element = this->expression[index];
		switch (this->checkElement(element))
		{
		case SPACE:
			break ;

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
		index++;
	}
	if (this->main_stack.size() != 1)
		printError();
	this->print();
}

void	RPN::print(void)
{
	std::cout << GRN << this->main_stack.top() << std::endl;
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
	if (element == ' ')
		return (SPACE);
	else if (isdigit(element))
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
	if (this->main_stack.size() < 2)
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

void	printError(void)
{
	std::cout << RED << "Error" << std::endl;
	exit(1);
}
