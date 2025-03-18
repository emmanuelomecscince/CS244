#include <iostream>

int main() {
    int number;
    std::cout << "Enter a positive integer: ";
    std:: cin >> number;
    if (number > 0) {
        std:: cout << "Factors of " << number << " are: "; 
        for (int i = 1; i < number; ++i) {
            if (number % i == 0) {
                std:: cout << i << " ";
            }
        }
        std:: cout << std:: endl;
    } else {
        std:: cout << "Please enter a positive integer." << std::endl;
}
return 0; 

    }


