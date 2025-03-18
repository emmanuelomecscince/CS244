#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip> //fixed(), setprecision()
#include <stdexcept>

namespace dsn
{
    //Interface 
    class Object 
    {
        virtual std::string toString() const = 0;

        friend std::ostream& operator<<(std::ostream& out,const Object& obj)
        {
            return out << obj.toString();
        }
    };

    //Interface 
    class Polygon : public Object  
    {
        public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual int sides() const = 0;
    };

    //Abstract Class
    class RegularPolygon : public Polygon 
    {
        private:
        double len;

        public:
        RegularPolygon() : len(1) {}

        RegularPolygon(const RegularPolygon& obj) 
        {
            len = obj.len;
        }

        RegularPolygon& operator=(const RegularPolygon& rhs)
        {
            if(this != &rhs)
            {
                len = rhs.len;
            }
            return *this;
        }

        virtual ~RegularPolygon() {}

        double length() const {return len;}

        void length(double value) 
        {
            if(value > 0)
            {
                len = value;
            }
        }

        double perimeter() const override
        {
            return len * sides();
        }

        std::string toString() const override
        {
            std::stringstream out;

            out << "(";
            out << std::fixed << std::setprecision(2);

            for(int i = 0;i < sides();i += 1)
            {
                out << len;

                if(i + 1 < sides())
                {
                    out << ",";
                }
            }
            out << ")";
            return out.str();
        }
    };

    class Square : public RegularPolygon 
    {
        public: 
        Square() {}
        Square(double value) {length(value);}
        Square(const Square& obj) : RegularPolygon(obj) {}
        
        Square& operator=(const Square& rhs)
        {
            if(this != &rhs)
            {
                RegularPolygon::operator=(rhs);
            }
            return *this;
        }

        ~Square() {}
        int sides() const override {return 4;}
        double area() const override {return pow(length(),2);}
    };

    class EquilateralTriangle : public RegularPolygon 
    {
        public: 
        EquilateralTriangle() {}
        EquilateralTriangle(double value) {length(value);}
        EquilateralTriangle(const EquilateralTriangle& obj) : RegularPolygon(obj) {}
        
        EquilateralTriangle& operator=(const EquilateralTriangle& rhs)
        {
            if(this != &rhs)
            {
                RegularPolygon::operator=(rhs);
            }
            return *this;
        }

        ~EquilateralTriangle() {}
        int sides() const override {return 3;}
        double area() const override {return 0.5 * pow(length(),2) * sin(3.14159265/3);}
    };
}

#endif

