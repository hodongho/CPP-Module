#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
	Contact	Contacts[8];
	int		index;

	public:
	void	init();
	void	add_contacts();
	void	search();
};

#endif
