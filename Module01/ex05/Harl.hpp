#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl //pas de données membres
{
private :
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public :
	void complain(std::string level);
};

#endif
