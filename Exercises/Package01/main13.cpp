#include <iostream> //cout, cin
#include <cctype> //isalpha(), toupper()

int main()
{
    char a, b;

    std::cout << "Enter first character: ";
    std::cin >> a;
    std::cout << "Enter second character: ";
    std::cin >> b;

    if(isalpha(a) && isalpha(b))
    {
        a = toupper(a);
        b = toupper(b);

        if(a < b)
        {
            std::cout << a << b << "\n";
        }
        else 
        {
            std::cout << b << a << "\n";
        }
    }
    return 0;
}