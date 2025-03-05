#include <iostream>
#include <string>

// Using long long instead of int because large numbers (like 600851475143) 
// are much larger than int's maximum value of 2^31-1 (2,147,483,647)
int largestPrimeFactor(long long n) {
    long long largestFactor = 0;
    
    // First handle all factors of 2 to make the number odd
    // This simplifies the rest of the factorization
    while (n % 2 == 0) {
        largestFactor = 2;
        n /= 2;
    }
    
    // Now check odd numbers up to sqrt(n) for factors
    // We only need to check up to sqrt(n) because if n has a prime factor larger than sqrt(n),
    // it can only have one such factor
    for (long long i = 3; i * i <= n; i += 2) {
        // Keep dividing by i as long as it's a factor
        // This removes all occurrences of the prime factor i
        while (n % i == 0) {
            largestFactor = i;
            n /= i;
        }
    }
    
    // If n is still greater than 2 after the above process,
    // then n itself is prime and is the largest prime factor
    if (n > 2) {
        largestFactor = n;
    }
    return largestFactor;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }

    try {
        long long number = std::stoll(argv[1]);
        if (number <= 0) {
            std::cout << "Please enter a positive number" << std::endl;
            return 1;
        }
        std::cout << "The largest prime factor of " << number << " is: " 
                  << largestPrimeFactor(number) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Invalid input. Please enter a valid number" << std::endl;
        return 1;
    }
    
    return 0;
}
