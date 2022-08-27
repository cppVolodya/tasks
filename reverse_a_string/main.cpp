#include <iostream>
#include <string>
#include <algorithm>


int main()
{
    std::cout << "Enter the string: ";
    std::string str;
    std::getline(std::cin, str);

    std::reverse(str.begin(), str.end());
    std::cout << "Reverse string: " << str << std::endl;

    std::cin.get();
    return 0;
}