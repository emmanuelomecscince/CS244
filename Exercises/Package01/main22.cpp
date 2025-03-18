#include <iostream>
#include <cctype> // for tolower funtion

int main() {
    char input; 
    const char specificLetter = 'x'; // Change 'x' to the desired specific letter 

    do {
        std::cout << "Enter a letter: "; 
        std::cin >> input; 
    } while (tolower(input) != specificLetter); 

    std::cout << "You enterd the specific letter: " << specificLetter << std:: endl; 
    return 0; 
}