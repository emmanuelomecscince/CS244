#ifndef PROH_H
#define PROP_H

#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

namespace PropertyA {
    bool Property(int arr[], int size) {
        for (int i = 0; i < size - 2; ++i) {
            if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]) {
                return true;
            }
        }
        return false;
    }
}

namespace PropertyB {
    bool Property(int arr[], int size) {
        unordered_map<int, int> count;
        for (int i = 0; i < size; ++i) {
            count[arr[i]]++;
            if (count[arr[i]] >= 3) {
                return true;
            }
        }
        return false;
    }
}

namespace PropertyC {
    bool Property(int arr[], int size) {
        bool increasing = true, decreasing = true;
        for (int i = 1; i < size; ++i) {
            if (arr[i] < arr[i - 1]) {
                increasing = false;
            }
            if (arr[i] > arr[i - 1]) {
                decreasing = false;
            }
        }
        return increasing || decreasing;
    }
}

namespace PropertyD {
    bool Property(fstream &file) {
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            return true;
        }
        return false;
    }
}

# endif

