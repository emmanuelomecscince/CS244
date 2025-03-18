# include <iostream>

int main() {
    int size;

    std::cout << "Enter an integer in the range [2-10]: ";
    std::cin >> size;

    if (size >= 2 && size <= 10) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << "* ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Input is out of range. Please enter a number between 2 and 10." << std::endl;
    }
    return 0;

}

