#include <iostream>
#include <limits> // For numeric_limits 

// Function to calculate the sum of array elements 
void Sum(double arr[], int size, double* result) {
    *result = 0; 
    for (int i = 0; i < size; ++i) {
        *result += arr[i]; 
    }
}

// Function to swap values of three integers 
void Swap(int* a, int* b, int* c) {
    int temp = *a; 
    *a = *b; 
    *b = *c; 
    *c = temp; 
}

// Function to create a new dynamic array 
int* NewArray() {
    int size;
    do {
        std::cout << "Enter the size of the array (minimum 3): "; 
        std::cin >> size; 
    } while (size < 3); 

    int* arr = new int[size]; // Allocate dynamic memory 
    std::cout << "Enter " << size << " elements for the array:\n"; 
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i]; 
    }
    return arr; // Return the pointer to the dynamic array
}

// Function to find the lowest value in an array 
void LowestScore(double arr[], int size, double* lowest) {
    *lowest = std::numeric_limits<double>::max(); // Initialize to the maximum possible value 
    for (int i = 0; i < size; ++i) {
        if (arr[i] < *lowest) {
            *lowest = arr[i]; 
        }
    }
}

// Main function to test the above functions 
int main() {
    // Test Sum()
    double arr1[] = {1.2, 2.3, 3.4, 4.5};
    int size1 = 4; 
    double sumResult;
    Sum(arr1, size1, &sumResult);
    std::cout << "Sum of array elements: " << sumResult << std::endl;
    
    // Test Swap()
    int x = 1, y = 2, z = 3; 
    std::cout << "Before Swap: x =" << x << ", y = " << y << ", z = " << z << std::endl; 
    Swap(&x, &y, &z);
    std::cout << "After Swap:  x = " << x << ", y = " << y << ", z = " << z << std::endl; 
    
    // Test NewArry()
    int* newArr = NewArray(); 
    std::cout << "New dynamic array created." << std::endl; 
    delete[] newArr; // Deallocate dynamic memory 

    // Test LowestScore()
    double arr2[] = {5.6, 3.2, 8.1, 2.9}; 
    int size2 = 4; 
    double lowest; 
    LowestScore(arr2, size2, &lowest); 
    std::cout << "Lowest score in the array: " << lowest << std::endl; 

    return 0; 
}