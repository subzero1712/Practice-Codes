int* printDivisors(int n, int &size){
  int* arr = new int[n]; 
    size = 0; 

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            arr[size] = i; 
            size++; 
        }
    }

    return arr; 
}
//2nd Approach
#include <math.h>
#include <bits/stdc++.h>
int* printDivisors(int n, int &size){
    int* arr = new int[n]; // Correct dynamic allocation
    size = 0;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            arr[size] = i;
            size++;
            if (n / i != i) { // Avoid adding the square root twice
                arr[size] = n / i;
                size++;
            }
        }
    }

    // Sort the array up to the size of the divisors
    std::sort(arr, arr + size);

    return arr; // Return the sorted array
}
