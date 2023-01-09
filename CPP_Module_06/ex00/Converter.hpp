#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
};

class Converter	{
	private:
		std::string	str;
		Type 		type;
	public:
		Converter();
		Converter(std::string str);
		Converter(Converter& copy);

		Converter& operator=(Converter& copy);

		virtual ~Converter();

		const std::string&	getStr() const;
		const Type&			getType() const;
		void				setType();

		void				isChar();
		void				isInt();
		void				isFloat();
		void				isDouble();

		void				print();
		void				printChar();
		void				printInt();
		void				printFloat();
		void				printDouble();
		void				printOther();
};

#endif
