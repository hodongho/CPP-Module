#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# define R_SIGN 72
# define R_EXEC 45

class RobotomyRequestForm : public AForm {
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm& copy);

		RobotomyRequestForm&	operator=(RobotomyRequestForm& copy);

		~RobotomyRequestForm();

		const std::string&	getTarget() const;
		void				execute(Bureaucrat const & executor) const;
};

#endif
