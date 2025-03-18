#include <iostream> 
#include <cmath>
using namespace std; 

bool isPrime(int num) {
    if (num < 2) return false; 
    for (int i = 2; i <= sqrt (num); i++) {
        if (num % i ==0) return false;
    }
    return true; 
}

int main() {
    int num; 
    cout << "Enter an integer: "; 
    cin >> num; 

    num = abs(num); // Take the absolute value of the number 
    int largestPrimeFactor = -1; 

    for (int i ; i < 13; i ++) { 
        if (num % i == 0 && isPrime(i)) {
            largestPrimeFactor = i; 
        }
    }
    
    if (largestPrimeFactor != -1) {
        cout << "The largest prime factor of" << num << " in the range [2-13] is: "
        << largestPrimeFactor <<endl; 
    } else {
        cout << "No prime factors of" << num << " exist in the range [2-13]. \n"; 
    }

    return 0; 
}