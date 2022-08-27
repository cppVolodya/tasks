#include <iostream>
#include <string>


int main()
{
    std::cout << "Enter the string: ";
    std::string str;
    std::getline(std::cin, str);

    std::string::iterator begin = str.begin();
    std::string::iterator end   = str.end() - 1;

    bool check{ true };
    for(int i { 0 }; i < str.size() / 2; ++i)
    {
        if (*begin++ != *end--)
        {
            check = false;
            break;
        }
    }

    if(check)
    {
        std::cout << "Entered string is a 'palindrom'!\n";
    }
    else
    {
        std::cout << "Entered string is not a 'palindrom'!\n";
    }

    std::cin.get();
    return 0;
}
