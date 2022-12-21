#include <iostream>
#include "Content.hpp"


std::string Friend::get_first_name(void) const {return (this->first_name);}
std::string Friend::get_last_name(void) const	{return (this->last_name);}
std::string Friend::get_nickname(void) const	{return (this->nickname);}
std::string Friend::get_phone_number(void) const	{return (this->phone_number);}
std::string Friend::get_memo(void) const	{return (this->memo);}
int Friend::get_id(void) const	{return (this->id);}

void Friend::set_first_name(std::string first_name) {this->first_name = first_name;}
void Friend::set_last_name(std::string last_name)	{this->last_name = last_name;}
void Friend::set_nickname(std::string nickname)	{this->nickname = nickname;}
void Friend::set_phone_number(std::string phone_number)	{this->phone_number = phone_number;}
void Friend::set_memo(std::string memo)	{this->memo = memo;}
void Friend::set_id(int id)	{this->id = id;}


void Friend::print_info(void)
{
	std::cout << "id : " << get_id() << std::endl;
	std::cout << "First_name : " << get_first_name() << std::endl;
	std::cout << "Last_name : " << get_last_name() << std::endl;
	std::cout << "Nickname : " << get_nickname() << std::endl;
	std::cout << "Phone_number : " << get_phone_number() << std::endl;
	std::cout << "memo : " << get_memo() << std::endl;
}