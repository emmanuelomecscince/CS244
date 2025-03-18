#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip> //fixed(), setprecision()
#include <stdexcept>

namespace oopn
{
    //Interface 
    class Object 
    {
        //pure virtual method
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

    //Abstract Class - fails to override sides() and area()
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

    //Concrete Class
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

    class IrregularPolygon : public Polygon 
    {
        private: 
        double* lens;
        int count;

        public:
        IrregularPolygon() : count(3)
        {
            lens = new double[count];
            for(int i = 0;i < count;i += 1)
            {
                lens[i] = 1.0;
            }
        }

        IrregularPolygon(int count) : count(count) 
        {
            if(count < 3) {count = 3;}
            lens = new double[count];
            for(int i = 0;i < count;i += 1) {lens[i] = 1.0;}
        }

        IrregularPolygon(const IrregularPolygon& obj) : IrregularPolygon(obj.count)
        {
            for(int i = 0;i < sides();i += 1) {lens[i] = obj.lens[i];}
        }

        IrregularPolygon& operator=(const IrregularPolygon& rhs)
        {
            if(this != &rhs && count == rhs.count)
            {
                for(int i = 0;i < sides();i += 1) {lens[i] = rhs.lens[i];}
            }
            return *this;
        }

        virtual ~IrregularPolygon() {delete[] lens;}

        double perimeter() const override
        {
            double sum = 0.0;

            for(int i = 0;i < sides();i += 1) {sum += lens[i];}
            return sum;
        }

        int sides() const override {return count;}

        double length(int idx) const 
        {
            if(idx >= 0 && idx < sides())
            {
                return lens[idx];
            }
            return 0.0;
        }

        void length(int idx,double value)
        {
            if(idx >= 0 && idx < sides() && value > 0)
            {
                lens[idx] = value;
            }
        }

        std::string toString() const override
        {
            std::stringstream out;

            out << "(";
            out << std::fixed << std::setprecision(2);

            for(int i = 0;i < sides();i += 1)
            {
                out << lens[i];

                if(i + 1 < sides())
                {
                    out << ",";
                }
            }
            out << ")";
            return out.str();
        }
    };

    class Rhombus : public IrregularPolygon
    {
        private:
        double diagonals[2];

        public: 
        Rhombus() : IrregularPolygon(4), diagonals{1.0,2.0} {}
        
        Rhombus(double value) : IrregularPolygon(4), diagonals{1.0,2.0} 
        {
            for(int i = 0;i < sides();i += 1)
            {
                length(i,value);
            }
        }

        Rhombus(const Rhombus& obj) : IrregularPolygon(obj) 
        {
            for(int i = 0;i < 2;i += 1)
            {
                diagonals[i] = obj.diagonals[i];
            }
        }

        Rhombus& operator=(const Rhombus& rhs)
        {
            if(this != &rhs)
            {
                IrregularPolygon::operator=(rhs);

                for(int i = 0;i < 2;i += 1)
                {
                    diagonals[i] = rhs.diagonals[i];
                }
            }
            return *this;
        }

        ~Rhombus() {}

        double diagonal(int idx) const 
        {
            if(idx >= 0 && idx < 2)
            {
                return diagonals[idx];
            }
            return 0.0;
        }

        void diagonal(int idx, double value)
        {
            if(idx >= 0 && idx < 2 && value > 0)
            {
                diagonals[idx] = value;
            }
        }

        double area() const override
        {
            return (diagonals[0] * diagonals[1]) / 2.0;
        }
    };

    class Rectangle : public IrregularPolygon
    {
        private:
        using IrregularPolygon::length;
        
        public: 
        Rectangle() : IrregularPolygon(4) {}
        
        Rectangle(double a,double b) : IrregularPolygon(4)
        {
            double m[2];
            
            if(a > b)
            {
                m[0] = a;
                m[1] = b;
            }
            else 
            {
                m[0] = b;
                m[1] = a;
            }

            for(int i = 0;i < 2;i += 1)
            {
                IrregularPolygon::length(i,m[i]);
                IrregularPolygon::length(i+2,m[i]);
            }
        }

        Rectangle(const Rectangle& obj) : IrregularPolygon(obj) {}

        Rectangle& operator=(const Rectangle& rhs)
        {
            if(this != &rhs)
            {
                IrregularPolygon::operator=(rhs);
            }
            return *this;
        }

        ~Rectangle() {}

        double length() const {return IrregularPolygon::length(0);}

        double width() const {return IrregularPolygon::length(1);}

        void length(double value) 
        {
            if(value > 0 && value >= IrregularPolygon::length(1))
            {
                IrregularPolygon::length(0,value);
                IrregularPolygon::length(2,value);
            }
        }

        void width(double value) 
        {
            if(value > 0 && value <= IrregularPolygon::length(0))
            {
                IrregularPolygon::length(1,value);
                IrregularPolygon::length(3,value);
            }
        }

        double area() const override
        {
            return IrregularPolygon::length(0) * IrregularPolygon::length(1);
        }
    };
}

#endif