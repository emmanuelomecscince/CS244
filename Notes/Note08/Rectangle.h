#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace oopn 
{
    class Rectangle 
    {
        private:
        double length;
        double width;

        public:
        //Default Constructor 
        Rectangle() : width(1), length(1) {}

        //Copy Constructor 
        Rectangle(const Rectangle& obj)
        {
            width = obj.width;
            length = obj.length;
        }

        //Assignment Operator 
        Rectangle& operator=(const Rectangle& rhs)
        {
            if(this != &rhs)
            {
                width = rhs.width;
                length = rhs.length;
            }
            return *this;
        }

        //Destructor 
        ~Rectangle() {} 

        //Getter Methods
        double Length() const {return length;}

        double Width() const {return width;}

        //Setter Methods
        void setLength(double value)
        {
            if(value > 0 && value >= width)
            {
                length = value;
            }
        }

        void setWidth(double value)
        {
            if(value > 0 && value <= length)
            {
                width = value;
            }
        }

        double perimeter() const {return 2 * (length + width);}

        double area() const {return length * width;}

        std::string toString() const 
        {
            std::stringstream out;

            out << std::fixed << std::setprecision(2);
            out << "[" << width << "," << length << "]";
            return out.str();
        }

        friend std::ostream& operator<<(std::ostream& out,const Rectangle& obj)
        {
            out << obj.toString();
            return out;
        }
    };
}

#endif