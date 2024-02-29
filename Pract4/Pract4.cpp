#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
void naoborot(const std::string& word) 
{
    std::string reversedWord(word.rbegin(), word.rend());
    std::cout << "Слово задом наперед: " << reversedWord << std::endl;
}

void glassnie(const std::string& word) 
{
    std::string wordWithoutVowels;
    for (char c : word) 
    {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' && c != 'Y') 
        {
            wordWithoutVowels += c;
        }
    }
    std::cout << "Слово без гласных: " << wordWithoutVowels << std::endl;
}

void soglasnie(const std::string& word)
{
    std::string wordWithoutConsonants;
    for (char c : word) 
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
        {
            wordWithoutConsonants += c;
        }
    }
    std::cout << "Слово без согласных: " << wordWithoutConsonants << std::endl;
}

void peremeshat(const std::string& word) 
{
    std::string scrambledWord(word);
    std::shuffle(scrambledWord.begin(), scrambledWord.end(), std::mt19937(std::time(0)));
    std::cout << "Раскиданные буквы заданного слова: " << scrambledWord << std::endl;
}

int main() 
{
    while (true)
    {
        setlocale(LC_ALL, "RUS");
        std::string word;
        int choice;

        std::cout << "Введите слово на английском: ";
        std::cin >> word;

        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Вывести слово задом наперед" << std::endl;
        std::cout << "2. Вывести слово без гласных" << std::endl;
        std::cout << "3. Вывести слово без согласных" << std::endl;
        std::cout << "4. Рандомно раскидывать буквы заданного слова" << std::endl;
        std::cout << "5. Ввести другое слово" << std::endl;
        std::cout << "Введите номер действия (1-5): ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1:
            naoborot(word);
            break;
        case 2:
            glassnie(word);
            break;
        case 3:
            soglasnie(word);
            break;
        case 4:
            peremeshat(word);
            break;
        case 5:
            break;
        default:
            std::cout << "Неверный выбор действия." << std::endl;
        }
    }

    return 0;
}