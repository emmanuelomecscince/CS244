#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Object.h"
#include "Professor.h"

namespace oopn
{
    class Department : public Object
    {
        private:
        std::string name;
        //Aggregation Relationship
        Professor *professors[30];
        size_t count;

        public:
        
        Department() : count(0)
        {
            name = "Department";
        }

        Department(const Department& obj){
            name = obj.name;
            count = obj.count;

            for(int i = 0;i < count;i += 1)
            {
                professors[i] = obj.professors[i];
            }
        }
        Department& operator=(const Department& other)
        {
            if(this != &other)
            {
               name = other.name;
               count = other.count;

               for(int i = 0;i < count;i += 1)
               {
                    professors[i] = other.professors[i];
               }
            }
            return *this;
        }

        ~Department(){}

        std::string title() const
        {
            return name;
        }

        void title(std::string str){
            name = str;
        }

        void addProfessor(Professor* obj){
            if(count < 30 && obj!=nullptr){
                professors[count] = obj;
                count++;
            }
        }

        std::string toString() const override{
            std::stringstream out;
            out<<name << "\n\n";

            for(int i = 0;i < count;i += 1)
            {
                out << "+ " << *(professors[i]) << "\n";
            }
            return out.str();
        }
        
    };
}

#endif