#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace oopn 
{
    class Circle 
    {
        private:
        double radius;
        static const double PI;

        public:
        //Default Constructor 
        Circle() : radius(1) {}

        //Copy Constructor 
        Circle(const Circle& obj)
        {
            radius = obj.radius;
        }

        //Assignment Operator 
        Circle& operator=(const Circle& rhs)
        {
            if(this != &rhs)
            {
                radius = rhs.radius;
            }
            return *this;
        }

        //Destructor 
        ~Circle() {} 

        //Getter Methods
        double getRadius() const {return radius;}

        //Setter Methods
        void setRadius(double value)
        {
            if(value > 0)
            {
                radius = value;
            }
        }

        double circumference() const {return 2 * radius * PI;}

        double area() const {return PI * radius * radius;}

        std::string toString() const 
        {
            std::stringstream out;

            out << std::fixed << std::setprecision(2);
            out << "(" << radius << ")";
            return out.str();
        }

        friend std::ostream& operator<<(std::ostream& out,const Circle& obj)
        {
            out << obj.toString();
            return out;
        }
    };

    const double Circle::PI = 3.1415926;
}

#endif