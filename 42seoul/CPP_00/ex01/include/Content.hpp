#ifndef __CONTENT_H__
#define __CONTENT_H__

# include <iostream>
# include <string>
# include <iomanip>

class Friend
{
	public :
	std::string get_first_name(void) const;
	std::string get_last_name(void) const;
	std::string get_nickname(void) const;
	std::string get_phone_number(void) const;
	std::string get_memo(void) const;
	int get_id(void) const;

	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_nickname(std::string nickname);
	void set_phone_number(std::string phone_number);
	void set_memo(std::string id);
	void set_id(int id);

	void print_info(void);

	private :
	int			id;
	std::string	memo;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
};

#endif