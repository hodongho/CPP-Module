#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
	private:
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	public:
	void	set_index(int _index);
	void	add_contact(std::string input, int i);
	void	search();
	void	display();
};

#endif
