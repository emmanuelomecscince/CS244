#include <iostream>
#include <cctype>
#include <string>

std::string Format(const std::string& str) {
    std::string copy;
    bool capitalize = true; // Capitalize the first letter after a space

    for (char ch : str) {
        if (!std::isalpha(ch) && ch != ' ') {
            return ""; // Return empty string if invalid character is found
        }
        if (std::isalpha(ch)) {
            if (capitalize) {
                copy += std::toupper(ch);
                capitalize = false;
            } else {
                copy += std::tolower(ch);
            }
        } else if (ch == ' ') {
            capitalize = true; // Set flag to capitalize next letter
        }
    }
    return copy;
}

int main() {
    std::string test1 = "The new eNtraNcE";
    std::string test2 = "All for 1and2";
    
    std::cout << "Formatted: " << Format(test1) << std::endl;
    std::cout << "Formatted: " << Format(test2) << std::endl;
    
    return 0;
}