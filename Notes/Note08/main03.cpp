#include "Deck.h"

int main()
{
    unsigned int n = 52;
    std::string* a = oopn::CreateDeckEmpty(n);
    oopn::StandardPopulate(a,n,"A23456789TJQK","SCDH");
    oopn::DisplayDeck(a,n,4);
    delete[] a;
    return 0;
}
