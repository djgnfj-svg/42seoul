#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

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