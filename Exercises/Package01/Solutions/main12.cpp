#include <iostream> //cout, cin

int main()
{
    double x, y;

    std::cout << "Enter first number: ";
    std::cin >> x;
    std::cout << "Enter second number: ";
    std::cin >> y;

    if(x > y)
    {
        std::cout << x;
    }
    else 
    {
        std::cout << y;
    }
    std::cout << "\n";
    //std::cout << (x > y)?(x):(y) << "\n";
    return 0;
}