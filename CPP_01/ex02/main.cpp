#include <iostream>

int main(void)
{
    // 결국 가르키는 것은 str의 이름이기 때문에 그곳에 str2를 넣는다면 그저 str = str2이런 느낌인 것이다
    // 고로 메모리는 변화가 없다.
    std::string str = "HI THIS IS BRAIN";
    std::cout << str << std::endl;
    std::cout << &str << std::endl;
    std::cout << "=======" << std::endl;
    std::string str2 = "HI THIS IS BRAIN22";
    std::string str3 = "HI THIS IS BRAIN33";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    stringREF = str2;
    stringREF = str3;
    std::cout << "=======" << std::endl;

    std::cout << str << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;

    std::cout << &str << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    std::cout << "=======" << std::endl;
}