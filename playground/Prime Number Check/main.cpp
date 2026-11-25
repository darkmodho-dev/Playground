#include <iostream>

int main() {
    long long number;
    std::cout << "Enter an integer: ";

    if (!(std::cin >> number)) {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    if (number < 2) {
        std::cout << number << " is not prime.\n";
        return 0;
    }

    bool isPrime = true;
    for (long long divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {
            isPrime = false;
            break;
        }
    }

    std::cout << number << (isPrime ? " is prime.\n" : " is not prime.\n");
    return 0;
}
