#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# define S_SIGN 145
# define S_EXEC 137

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm& copy);

		ShrubberyCreationForm&	operator=(ShrubberyCreationForm& copy);

		~ShrubberyCreationForm();

		const std::string&	getTarget() const;
		void				execute(Bureaucrat const & executor) const;
};

#endif
