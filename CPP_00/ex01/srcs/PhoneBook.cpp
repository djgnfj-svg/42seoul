#include "Content.hpp"

static int	check_over_range(unsigned long long sum, int sign)
{
	return (sum * sign);
}

int			ft_atoi(const char *str)
{
	int			i;
	int			is_negative;
	long long	result;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	is_negative = (str[i] == '-') ? -1 : 1;
	if (is_negative == -1 || str[i] == '+')
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	result = check_over_range(result, is_negative);
	return (result);
}

void show_welcome(void)
{
	std::cout << "========HIYO========" << std::endl;
	std::cout << "choise ADD, SEARCH, EXIT" << std::endl;
}

Friend ADD(int id)
{
	std::string temp;
	Friend temp_friend;

	std::cout << "first_name : ";
	std::getline(std::cin, temp);
	temp_friend.set_first_name(temp);
	std::cout << "Last_name : " ;
	std::getline(std::cin, temp);
	temp_friend.set_last_name(temp);
	std::cout << "Nickname : " ;
	std::getline(std::cin, temp);
	temp_friend.set_nickname(temp);
	std::cout << "Phone_number : " ;
	std::getline(std::cin, temp);
	temp_friend.set_phone_number(temp);
	std::cout << "memo : " ;
	std::getline(std::cin, temp);
	temp_friend.set_memo(temp);
	temp_friend.set_id(id + 1);
	return temp_friend;
}
void SEARCH_check(std::string str)
{
	if (str.length() > 10)
		std::cout << std::setw(10) << str.substr(0,9).append(".");
	else
		std::cout<< std::setw(10) << str;
	std::cout << '|';
}

void SEARCH(Friend Phone_book[8], int friend_count)
{
	if (friend_count <= 0)
	{
		std::cout << "you don't have friend" << std::endl;
		return ;
	}
	for(int i = 0; i < friend_count; i++)
	{
		std::cout<< std::setw(10) << Phone_book[i].get_id() << '|';
		SEARCH_check(Phone_book[i].get_first_name());
		SEARCH_check(Phone_book[i].get_last_name());
		SEARCH_check(Phone_book[i].get_nickname());
		std::cout << std::endl;
	}
	std::cout << "따로 찾으시는 분의 ID를 입력해 주세요(없으면 0을 입력해주세요 :";
	int index;
	std::string input;
	getline(std::cin, input);
	if (std::cin.eof())
		return;
	if(std::cin.bad())
		return;
	index = ft_atoi(input.c_str());
	if (index == 0)
		return ;
	else if (0 < index && index < 9 && index <= friend_count )
	{
		Phone_book[index-1].print_info();
	}
	else
		std::cout << "입력값이 올바르지 않습니다."<< std::endl;
}

int main(void)
{
	std::string input;
	Friend friends[8];
	int		friend_count;
	bool	full;

	friend_count = 0;
	full = false;
	while(42)
	{
		show_welcome();
		getline(std::cin, input);
		if (input == "ADD")
		{
			if (friend_count >= 8)
			{
				friend_count = friend_count % 8;
				full = true;
			}
			friends[friend_count] = ADD(friend_count);
			friend_count++;
		}
		else if (input == "SEARCH")
		{
			if (full)
				SEARCH(friends, 8);
			else
				SEARCH(friends, friend_count);
		}
		else if (input == "EXIT")
			break;
		if(std::cin.bad())
			break;
		if (std::cin.eof())
			break;
	}
	return 0;
}