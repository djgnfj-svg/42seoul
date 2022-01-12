#include <iostream>

int main(void)
{
    // 결국 가르키는 것은 str의 이름이기 때문에 그곳에 str2를 넣는다면 그저 str = str2이런 느낌인 것이다
    // 고로 메모리는 변화가 없다.
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    std::cout << "=======start=======" << std::endl;

    std::cout << "======value======" << std::endl;
    std::cout << str << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;

    std::cout << "======memory======" << std::endl;
    std::cout << &str << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    std::cout << "============" << std::endl;
    std::string str2 = "HI THIS IS BRAIN";
    stringPTR = &str2;
    stringREF = str2;
    // std::string &stringREF = str;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

}