#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain& copy);

		Brain& operator=(Brain& copy);

		~Brain();

		std::string const&	getIdea(int	i) const;
		void				setIdea(std::string idea, int i);
};

#endif
