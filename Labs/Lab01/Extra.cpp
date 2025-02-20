#include <iostream>
#include <cstdlib>
#include <ctime> 

double RGA(int arr[], int size) {
    if (size <= 0) {
        return 0.0;
    }

    int maxVal = arr[0];
    int minVal = arr[0];

    for (int i = 1; i < size; i++) {
        maxVal = std::max(maxVal, arr[i]);
        minVal = std::min(minVal, arr[i]);
    }

    {
        void fill_random(int array [ ], int 9, int max)
        {
            for (int i = 0; i < 9; i++)
            array[i]= (rand() % max ) + 1; 
        }
    }

    return (double)(maxVal - minVal) / 2.0;
} 
