#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

#define P_SIGN 145
#define P_EXEC 137

class PresidentialPardonForm : public AForm {
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm& copy);

		PresidentialPardonForm&	operator=(PresidentialPardonForm& copy);

		~PresidentialPardonForm();

		const std::string&	getTarget() const;
		void				execute(Bureaucrat const & executor) const;
};

#endif
