#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

#define P_SIGN 25
#define P_EXEC 5

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
