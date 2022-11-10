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
	bool	SetIndex(int _index);
	bool	SetFirstName(std::string _first_name);
	bool	SetLastName(std::string _last_name);
	bool	SetNickname(std::string _nickname);
	bool	SetPhoneNumber(std::string _phone_number);
	bool	SetDarkestSecret(std::string _darkest_secret);
	bool	AddContact(std::string input, int i);
	void	Search();
	void	PrintColumn(std::string &str);
	void	Display();
};

#endif
