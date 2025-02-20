#ifndef ECHO_H
#define ECHO_H
#include <string> 
namespace oopq
 {
     std:: string Echo(const std::string str)
     {
        return str + "\n" + str; 
     }

}