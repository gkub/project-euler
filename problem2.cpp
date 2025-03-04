#include <iostream>
// Gregory Kubiski-Moshansky
// 2025-03-04

// Project Euler Problem 2
// Find sum of all even Fibonacci numbers below 4 million
int main() {
    int n = 4000000;
    int sum = 0;
    int a = 1;
    int b = 2;
    
    // Loop while b is less than n
    while (b < n) {
        // Add b to sum if it's even
        if (b % 2 == 0) {
            sum += b;
        }
        // Calculate next Fibonacci number
        int temp = a + b;
        a = b;
        b = temp;
    }
    
    // Print result
    std::cout << sum << std::endl;
    return 0;
}