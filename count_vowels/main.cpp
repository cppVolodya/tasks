#include <iostream>
#include <string>
#include <algorithm>


int main()
{
    std::cout << "Enter the string: ";
    std::string str;
    std::getline(std::cin, str);

    int number_vowels{ 0 };
    auto temporary = str.begin();
    std::string vowels{ "aeiouy" };

    while(true)
    {
        temporary = std::find_first_of(temporary,      str.end(),
                                       vowels.begin(), vowels.end());
        if(temporary != str.end())
        {
            ++temporary;
            ++number_vowels;
            std::cout << "Number vowels: " << number_vowels << "\n";
        }
        else
        {
            break;
        }
    }

    std::cout << "Result 'number vowels': " << number_vowels << std::endl;

    std::cin.get();
    return 0;
}
