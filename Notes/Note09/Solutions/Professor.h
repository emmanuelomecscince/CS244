#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Object.h"

namespace oopn{
    class Professor : public Object
    {
      private:
      std::string name;
      
      public:
      Professor(){
        name = "Professor";
      }
      Professor(const Professor& other)
      {
        name = other.name;
      }
      Professor& operator=(const Professor& rhs){
        if(this != &rhs){
            name = rhs.name;
        }
        return *this;
      }
      ~Professor(){}
      std::string title() const{
        return name;
      }
      void title(std::string newName){
        name = newName;
      }
      std::string toString() const override{
        std::stringstream out;
        out<<name;
        return out.str();

      }
    };
}
#endif
