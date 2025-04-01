#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <sstream>

namespace oopn 
{
    class Object 
    {
        public:
        
        friend std::ostream& operator<<(std::ostream& out,const Object& obj)
        {
            return out << obj.toString();
        }

        virtual std::string toString() const=0;
    };
}
#endif