#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string> //string 
#include <sstream> //stringstream
#include <iostream> //cout
#include <cstdlib> //rand()
#include <ctime> 

namespace oopn
{
    class Customer 
    {
        public:
        std::string name;
        std::string number;
        static int num_gen; 
        static int count;

        //Default Constructor
        Customer() 
        {
            name = "John Smith";
            number = AccountNumberGenerator();
            count += 1;
            std::cout << "account: " << number << "\ncalled the default constructor\n";
        }

        //Copy Constructor
        Customer(const Customer& obj) 
        {
            this->name = obj.name;
            number = AccountNumberGenerator();
            count += 1;
            std::cout << "account: " << number << "\ncalled the copy constructor\n";
        } 

        //Copy Assignment Operator 
        Customer& operator=(const Customer& rhs) 
        {
            if(this != &rhs)
            {
                name = rhs.name;
                std::cout << "account: " << number << "\ncalled the copy assignment operator\n";
            }
        } 

        //Destructor 
        ~Customer() 
        {
            count -= 1;
            std::cout << "account: " << number << "\ncalled the destructor\n";
        }

        //Static Method
        static std::string AccountNumberGenerator() 
        {
            std::string result = "8";
            result += std::to_string(rand() % 10);
            result += std::to_string(rand() % 10);
            result += std::to_string(rand() % 10);
            result += std::to_string(num_gen);
            num_gen += 1;
            result += std::to_string(rand() % 10);
            result += std::to_string(rand() % 10);
            result += std::to_string(rand() % 10);
            result += std::to_string(rand() % 10); 
        }

        //Constant  
    };

    //Initializing Static Fields
    int Customer::num_gen = 1000;
    int Customer::count = 0;
}

#endif