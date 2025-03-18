#include "Derived.h"

int main() 
{
    oopn::DerivedA a;

    a.Base::publicMethod();
    a.publicMethod();
    return 0;
}