#ifndef DERIVED_H
#define DERIVED_H

#include <iostream>
#include <string>

namespace oopn
{
    class Base 
    {
        private:
        void privateMethod() 
        {
            std::cout << "This is the base class private method\n";
        }

        public:
        Base() 
        {
            std::cout << "This is the base class constructor\n";
        }

        ~Base() 
        {
            std::cout << "This is the base class destructor\n";
        }

        void publicMethod() 
        {
            std::cout << "This is the base class public method\n";
        }
    
        protected:
        void protectedMethod() 
        {
            std::cout << "This is the base class protected method\n";
        }
    };

    class DerivedA : public Base 
    {
        public:
        DerivedA() 
        {
            std::cout << "This is the derived A class constructor\n";
        }

        ~DerivedA() 
        {
            std::cout << "This is the derived A class destructor\n";
        }
        
        void DerivedPublicMethod() 
        {
            std::cout << "This is a derived public method that invokes the base public method\n";
            Base::publicMethod();
        }
    
        void DerivedProtectedMethod() 
        {
            std::cout << "This is a derived public method that invokes the base protected method\n";
            Base::protectedMethod();
        }

        void DerivedPrivateMethod() 
        {
            std::cout << "This is a derived public method that invokes the base private method\n";
            Base::privateMethod();
        }
    
    };
    class DerivedB : private Base 
    {
        
        public:
        DerivedB() 
        {
            std::cout << "This is the derived B class constructor\n";
        }

        ~DerivedB() 
        {
            std::cout << "This is the derived B class destructor\n";
        }
        
        void DerivedPublicMethod() 
        {
            std::cout << "This is a derived public method that invokes the base public method\n";
            Base::publicMethod();
        }
    
        void DerivedProtectedMethod() 
        {
            std::cout << "This is a derived public method that invokes the base protected method\n";
            Base::protectedMethod();
        }
    };

    class DerivedC : protected Base 
    {
        public:
        DerivedC() 
        {
            std::cout << "This is the derived C class constructor\n";
        }

        ~DerivedC() 
        {
            std::cout << "This is the derived C class destructor\n";
        }
        
        void DerivedPublicMethod() 
        {
            std::cout << "This is a derived public method that invokes the base public method\n";
            Base::publicMethod();
        }
    
        void DerivedProtectedMethod() 
        {
            std::cout << "This is a derived public method that invokes the base protected method\n";
            Base::protectedMethod();
        }        
    };
}
#endif