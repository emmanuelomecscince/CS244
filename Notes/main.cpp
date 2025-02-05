//Grade Book using Arrays
#include <string> // string, getline()
#include <iostream> // cout, cin
using namespace std;

void ReadNames(std:: string names[],int n)
{
    //std::cin.ignore();
    for(int i = 0;i < n;i += 1)
    {
        std::cout << "Enter name of student " << (i + 1) << ": ";
        std::getline(std::cin,names[i]);
    }
}

void ReadGrades(std::string names[], double grades[],int n)
{
    for(int i = 0;i < n;i += 1)
    {
        std::cout << "Enter grade of " << names[i] << ": ";

        while(true)
        {
            std::cin >> grades[i];

            if(grades[i] >= 0 && grades[i] <= 100)
            {
                break;
            }
            else
            {
                std::cout << "Invalid grade. Reenter grade: ";
            }
        }
    }
}
int main()
{
    const int n = 5;
    std::string students[n];
    double grades[n];
    ReadGrades(students,grades,n);

    for(int i = 0;i < n;i += 1)
    {
        std::cout << students[i] << " (" << grades[i] << ")";
    } 

    return 0; 
}