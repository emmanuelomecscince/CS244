#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Department.h"
#include <stdexcept>

namespace oopn 
{
    class University : public Object 
    {
        private:
        //Composition Relationship
        Department departments[100];
        size_t count;
        std::string name;

        public:
        University(){
            count = 0;
            name = "University";
        }
        University(const University&) = delete;
        University& operator=(const University&) = delete;
        ~University(){}
        std::string title() const
        {
            return name;
        }
        void title(const std::string& newName)
        {
            name = newName;
        }
        void newDepartment (std::string x){
            if(count < 100){
                departments[count].title(x);
                count++;
            }
        }

        Department& getDepartment(std::string str){
            for(int i = 0; i < count; i++){
                if(departments[i].title() == str){
                    return departments[i];
                } 
            }
            throw std::out_of_range("Department Not Found");
        }

        std::string toString() const override{
            std::stringstream out;
            out<<name<<"\n\n";
            for(int i = 0; i < count; i++){
                out<<departments[i]<<"\n";
            }
            return out.str();
        }
    };
}
#endif