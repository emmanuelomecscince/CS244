#include <iostream> 
#include "Prop.h" 
using namespace std; 

int main() {
    // Test PropertyA
    int arrA[] = {1, 2, 2, 2, 3};
    cout << "PropertyA: " << (PropertyA::Property(arrA, 5) ? "True" : "False") << endl; 

    // Test PropertyB
    int arrB[] = {1, 2, 3, 2, 2, 2}; 
    cout << "PropertyB: " << (PropertyB::Property(arrB, 6) ? "True" : "False") << endl;

    // Test PropertyC
    int arrC[] = {1, 2, 3, 4, 5}; 
    int arrC2[] = {5, 4, 3, 2, 1};
    int arrC3[] = {1, 3, 2, 4}; 
    cout << "PropertyC (Increasing): " << (PropertyC::Property(arrC, 5) ? "True" : "False") << endl; 
    cout << "PropertyC (Decreasing): " << (PropertyC::Property(arrC2, 5) ? "True" : "False") << endl; 
    cout << "PropertyC (Non-Monotonic): " << (PropertyC::Property(arrC3, 4) ? "True" : "False") << endl; 

    // Test PropertyD 
    fstream file("test.txt", ios::in); 
    cout << "PropertyD: " << (PropertyD::Property(file) ? "True" : "False") << endl; 
    file.close(); 

    return 0; 
}