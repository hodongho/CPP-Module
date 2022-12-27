#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:name(""), grade(LOWEST_G)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:name(name), grade(grade)
{
	if (grade < HIGHEST_G)
		throw(GradeTooHighException());
	else if (grade > LOWEST_G)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat& copy)
	:name(copy.getName()), grade(copy.getGrade())
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& copy)
{
	if (this != &copy)
	{
		grade = copy.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
	return (name);
}

const int& Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::increaseGrade()
{
	if (grade <= HIGHEST_G)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decreaseGrade()
{
	if (grade >= LOWEST_G)
		throw GradeTooLowException();
	grade++;
}

void	Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout	<< getName()
					<< " signed "
					<< f.getName()
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< getName()
					<< " couldn't sign "
					<< f.getName()
					<< " because "
					<< e.what()
					<< std::endl;
	}

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& Bureaucrat)
{
	out << Bureaucrat.getName()
		<< ", bureaucrat grade "
		<< Bureaucrat.getGrade();
	return (out);
}
