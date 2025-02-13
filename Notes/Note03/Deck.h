#ifndef DECK_H
#define DECK_H

 #include <string>

namespace oopn 
{
    /*objective: create a string, array to represent deck
    * Input: a size: */
   std::string* CreateDeckEmpty(unsigned int& n)
   {
       if(n > 0)\
       {
           return new std::string[n];
       }
       else 
       {

          n = 52;

          return new std::string[n]; 
       }
        
        /* 
        objective: populate the deck as a cross product of 
        * all the faces and suits.operator delete
        * Input: deck: string array size: unsinggend int, faces: string,
        * suits: string
        * constraint: If the product of the sizes of the faces and size.
        * 

        */
       void standardPoplulate(std::string deck[], unsigned int n,std:: string faces[i]) + suits[j];
       
       )
       {
         
       }
       }
    
   }

    

}

#endif 