#include <iostream>
// Gregory Kubiski-Moshansky
// 2025-03-04

// Project Euler Problem 1
// Find sum of all multiples of 3 or 5 below 1000
int main() {
    int n = 1000;
    int sum = 0;
    // Iterate through all numbers below n
    for (int i = 0; i < n; i++) {
        // Add number to sum if it's divisible by 3 or 5
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    // Print the final sum
    std::cout << sum << std::endl;
    return 0;
}