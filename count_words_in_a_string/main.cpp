#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <iterator>


enum class Actions
{
    EXIT,
    STRING,
    FILENAME
};

void EnterString();
void EnterFilename();
void RemovePunctuationMarks(std::string&);
template<typename T>
void CountWords(T&, std::map<std::string, int>&);
void ShowResult(const std::map<std::string, int>&);

int main()
{
    bool check{ true };
    while(check)
    {
        std::cout << "[1] --- Enter the string\n"
                     "[2] --- Enter the filename\n\n"
                     "[0] --- Exit\n";

        std::cout << "Choose: ";
        int action;
        std::cin >> action;

        switch( static_cast<Actions>(action) )
        {
            case Actions::STRING:
                EnterString();
                break;
            case Actions::FILENAME:
                EnterFilename();
                break;
            case Actions::EXIT:
                check = false;
                break;
            default:
                std::cout << "Incorrectly entered data!" << std::endl;
        }
    }

    return 0;
}

void EnterString()
{
    std::cout << "Enter the string: ";
    std::string str;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, str);

    std::istringstream iss{ str };
    std::map<std::string, int> number_words_in_string;

    CountWords(iss, number_words_in_string);
    ShowResult(number_words_in_string);
}

void EnterFilename()
{
    std::cout << "Enter the filename: ";
    std::string filename;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> filename;

    std::map<std::string, int> number_words_in_file;
    std::ifstream input_file{ filename };
    if( !input_file.is_open() )
    {
        std::cout << "The program cannot open this file for reading data: " << filename << "\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        exit(1);
    }

    CountWords(input_file, number_words_in_file);
    ShowResult(number_words_in_file);
}

void RemovePunctuationMarks(std::string& word)
{
    auto new_end = std::remove_if(word.begin(), word.end(), [](char& symbol)
    {
        return (( (symbol >= '!') && (symbol <= '@') ) ||
                ( (symbol >= '[') && (symbol <= '`') ) ||
                ( (symbol >= '{') && (symbol <= '~') ));
    });

    word.erase( new_end, word.end() );
}

template<typename T>
void CountWords(T& stream_data,
                std::map<std::string, int>& number_words_in_data)
{
    while(!stream_data.eof())
    {
        std::string word;
        stream_data >> word;
        RemovePunctuationMarks(word);
        if(auto i = number_words_in_data.find(word);
                i != number_words_in_data.end())
        {
            ++i->second;
        }
        else
        {
            if(!word.empty())
                number_words_in_data.insert({ word, 1});
        }
    }
}

void ShowResult(const std::map<std::string, int>& number_words_in_data)
{
    std::cout << "Number words in data: \n";
    for(const auto& i : number_words_in_data)
    {
        std::cout << std::setw(16) << std::left << i.first
                  << std::setw(4) << std::right << i.second << "\n";
    }

    std::cout << std::endl;
}