#include <string>
#include <iostream> //cout , cin

int main()
{
    int value;

    std::cout << "Enter an integer: ";
    std::cin >> value;

    if(value > 0 && value % 2 == 0)
    {
        std::cout << value << " is a positive even integer\n";
    }
    return 0;
}

