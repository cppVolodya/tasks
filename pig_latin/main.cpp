#include <iostream>
#include <string>
#include <algorithm>
#include <limits>


int main()
{
    std::cout << "Enter the word: ";
    std::string word;
    std::cin >> word;

    std::string word_pig_latin;
    word_pig_latin.resize(word.size() - 1);
    std::copy(word.begin() + 1, word.end(), word_pig_latin.begin());

    std::string ending{ "ay" };
    word_pig_latin += word[0] + ending;

    std::cout << "Pig Latin: " << word_pig_latin << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cin.get();
    return 0;
}