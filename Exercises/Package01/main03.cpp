#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cctype>

double Hypotenuse(double a, double b) {
    if (a > 0 && b > 0) {
        return std::sqrt(a * a + b * b);
    } else {
        return 0; 
    }
}

bool IsWord(std::string str) {
    for (char c : str) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
    return true; 
}

int Median(int a, int b, int c) {
    int arr[] = {a, b, c};
    std::sort(arr, arr + 3);
    return arr [1]; 
}

bool madeProfit(double NS, double SP, double SC, double PP, double PC) {
    if (NS > 0 && SP > 0 && SC > 0 && PP > 0 && PC > 0) {
        double profit = ((NS * SP) - SC) - ((NS * PP) + PC); 
        return profit > 0; 
    } else {
        return false; 
    }
}

int main() {
    // Test case for Hypotenuse()
    std::cout << Hypotenuse(3, 4) << std::endl; // OutPut: 5
    std::cout << Hypotenuse(-3, 4) << std::endl; // OutPut: 0 

    // Test cases for IsWord()
    std::cout << IsWord("hello") << std::endl; // Output: 1 (true)
    std::cout << IsWord("hello123") << std::endl; // Output: 0 (false)

    // Test cases for Median()
    std::cout << Median(1, 2, 3) << std::endl; // Output: 2
    std::cout << Median(3, 1, 2) << std::endl; // Output: 2

    // Test cases for madeProfit()
    std::cout << madeProfit(100, 50, 10, 20, 5) << std::endl; // Output: 1 (true)
    std::cout << madeProfit(100, 20, 10, 50, 5) << std::endl; // Output: 0 (false)

    return 0; 
}
