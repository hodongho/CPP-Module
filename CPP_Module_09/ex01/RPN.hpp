#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <iostream>

# define WHI "\e[1;37m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define BRW "\e[0;33m"
# define BLU "\e[0;34m"
# define PUP "\e[0;35m"
# define CYN "\e[0;36m"

enum Element {
	NUMBER,
	OPERATOR,
	SPACE,
	NONE
};

class RPN {
	private:
		std::stack<int>	main_stack;
		std::string		expression;

		void	setExpression(std::string _expression);

		void	print(void);
		Element	checkElement(const char& element);
		void	pushNumber(const char element);
		void	calculateStack(const char& element);

	public:
		RPN(void);
		RPN(const RPN& copy);
		RPN(std::string _expression);

		RPN&	operator=(const RPN& copy);

		~RPN(void);

		void	calculate(void);
};

void	printError(void);

#endif
