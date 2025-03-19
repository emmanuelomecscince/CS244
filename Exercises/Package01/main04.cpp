#include <iostream> 
#include <algorithm> // For std::sort 
using namespace std; 

// Funtion 1: Initialize 
void Initialize(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        arr[i] = value; 
    }
}

// Function 2: IsUnique 
bool IsUnique(const double arr[], int size) {
    for (int j = i + 1; j < size; j++) {
        if (arr[i] == arr [j]) {
            return false; 
        }
    }
    return true; 
}

// Fuction 3: Haswon 
bool HasWon(const int arr1[], const int arr2[]) {
    int sortedArr1[5], sortedArr2[5];
    for (int i = 0; i < 5; i++) {
        sortedArr1[i] = arr1[i];
        sortedArr2[i] = arr2[i];
    }
    sort(sortedArr1, sortedArr1 + 5);
    sort(sortedArr2, sortedArr2 + 5); 
    for (int i = 0; i < 5; i++) {
        if (sortedArr1[i] != sortedArr2[i]) {
            return false; 
        }
    }
    return true; 
}

// Function 4: TimesTable 
void TimesTable(int arr[]) {
    int index = 0;
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= 12; j++) {
            arr[index++] = i * j; 
        }
    }
}

// Main fuction to test the above fuctions 
int main() {
    // Test Initialize
    int arr1[10];
    Initialize(arr1, 10, 5);
    cout << "Array after Initialize: "; 
    for (int i = 0; i < 10; i++) {
        cout << arr1[i] << " "; 
    }
    cout << endl; 

    // Test IsUnque 
    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "IsUnique: " << (IsUnique(arr2, 5) ? "True" : "False") << endl; 
    double arr3[] = {1.1, 2.2, 3.3, 2.2, 5.5}; 
    cout << "IsUnique: " << (IsUnique(arr3, 5) ? "True" : "False") << endl; 

    // Test HasWon
    int arr4[] = {1, 2, 3, 4, 5};
    int arr5[] = {5, 4, 3, 2, 1};
    cout << "HasWon: " << (HasWon(arr4, arr5) ? "True" : "Fasle") << endl; 
    int arr6[] = {1, 2, 3, 4, 6}; 
    cout << "HasWon: " << (HasWon(arr4, arr6) ? "True" : "False") << endl; 

    // Test TimesTable
    int timesTable[144]; 
    TimesTable(timesTable); 
    cout << "TimesTable: "; 
    for (int i = 0; i < 144; i++) {
        cout << timesTable[i] << " "; 
        if ((i + 1) % 12 == 0) cout << endl; // Print in row of 12 
    }

    return 0; 
}
