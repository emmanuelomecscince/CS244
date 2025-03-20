#ifndef DECK_H
#define DECK_H

#include <string>
#include <iostream>

namespace oopn
{
    /*Objective: create a string array to represent deck
    * Input: a size: unsigned int
    * Algorithm: 
    * 1. if the size is zero, then assign 52 to size
    * 2. return dynamic string array with a size of size 
    */
    std::string* CreateDeckEmpty(unsigned int& n)
    {
        if(n == 0)
        {
            n = 52;
        }
        return new std::string[n];
    } 

    /*
    *Objective: Populate the deck as a cross product of 
    * all the faces and suits.
    *Inputs: deck: string array, size: unsigned int, faces: string,
    *suits: string
    *Constraint: If the product of the sizes of the faces and suits
    * exceeds the size of the array, do nothing.
    *Algorithm: 
    *1. If suits.length * faces.length <= size, then 
    *   1. for each i in faces, do 
    *       1. for each j in suits, do 
    *           1. deck[suits.length * i + j] <- faces[i] + suits[j] 
    */   
    void StandardPopulate(std::string* deck,unsigned int n,std::string faces,std::string suits)
    {
        if(faces.length() * suits.length() <= n)
        {
            for(int i = 0;i < faces.length();i += 1)
            {
                for(int j = 0;j < suits.length();j += 1)
                {
                    deck[i*suits.length()+j] += faces[i];
                    deck[i*suits.length()+j] += suits[j];
                }
            }
        }
    }

    /*Objective: To display the content of the deck
    *Input: deck: string array, size: unsigned int, suitCount: unsigned int
    *Algorithm: 
    *1. for each i in deck, do
    *   1. print i 
    *   2. if suitCount number of elements have been printed, start new line
    */
    void DisplayDeck(std::string* deck,unsigned int n,unsigned sc)
    {
        for(int i = 0;i < n;i += 1)
        {
            std::cout << deck[i];

            if((i + 1) % sc == 0)
            {
                std::cout << '\n';
            }
            else 
            {
                std::cout << ' ';
            }
        }
    }
}

#endif
