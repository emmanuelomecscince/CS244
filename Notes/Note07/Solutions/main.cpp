#include "Polygon.h"

void Stats(const oopn::RegularPolygon& obj)
{
    std::cout << "Length: " << obj.length() << "\n";
    std::cout << "Sides: " << obj.sides() << "\n";
    std::cout << "Perimeter: " << obj.perimeter() << "\n";
    std::cout << "Area: " << obj.area() << "\n";
    std::cout << obj << "\n";
}

int main()
{
    /*
    oopn::RegularPolygon* r[6] = {new oopn::Square(),new oopn::Square(5),new oopn::EquilateralTriangle(),new oopn::EquilateralTriangle(2),new oopn::EquilateralTriangle(4*sqrt(3)),new oopn::Square(4*sqrt(3))};

    for(int i = 0;i < 6;i += 1)
    {
        std::cout << "Regular Polygon " << (i + 1) << " stats:\n";
        Stats(*r[i]);
        std::cout << "\n";
        delete r[i];
    }
    */
    oopn::Rhombus r;
    oopn::Rectangle s;
    s.length(2.0);
    s.width(0.5);

    std::cout << r << "\n" << s << "\n";
    return 0;
}
