#include <iostream>
#include <string>
#include <sstream>

bool findWordInStatement(const std::string& statement, const std::string& word) {
    std::istringstream iss(statement);
    std::string currentWord;

    while (iss >> currentWord) {
        // Convert the current word and the word to find to lowercase for case-insensitive matching
        std::string lowercaseCurrentWord, lowercaseWord;
        for (char c : currentWord) {
            lowercaseCurrentWord += tolower(c);
        }
        for (char c : word) {
            lowercaseWord += tolower(c);
        }

        if (lowercaseCurrentWord == lowercaseWord) {
            return true;
        }
    }

    return false;
}

int main() {
    std::string statement;
    std::cout << "Enter a statement: ";
    std::getline(std::cin, statement);

    std::string word;
    std::cout << "Enter the word to find: ";
    std::cin >> word;

    if (findWordInStatement(statement, word)) {
        std::cout << "The word '" << word << "' is present in the statement.\n";
    } else {
        std::cout << "The word '" << word << "' is not found in the statement.\n";
    }

    return 0;
}
