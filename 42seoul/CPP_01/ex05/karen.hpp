#ifndef __KAREN_HPP__
# define __KAREN_HPP__

# include <iostream>

class Karen;

typedef struct s_complain
{
	std::string	level;
	void (Karen::*func_ptr)(void);
} t_complain;

class Karen
{
    public:
        void complain(std::string level);
        Karen();
    private:
        t_complain complain_list[4];
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif