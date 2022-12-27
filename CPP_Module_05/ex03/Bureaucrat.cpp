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
	grade--;
	if (grade < HIGHEST_G)
		throw GradeTooHighException();
}

void	Bureaucrat::decreaseGrade()
{
	grade++;
	if (grade > LOWEST_G)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout	<< getName()
					<< " signed "
					<< form.getName()
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout	<< getName()
					<< " couldn't sign "
					<< form.getName()
					<< " because "
					<< e.what()
					<< std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout	<< getName()
					<< " executed "
					<< form.getName()
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout	<< getName()
					<< " couldn't execute "
					<< form.getName()
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
