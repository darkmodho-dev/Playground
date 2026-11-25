#include "playground/exercises.hpp"

#include <cassert>
#include <iostream>

int main() {
    assert(playground::isPrime(2));
    assert(playground::isPrime(29));
    assert(!playground::isPrime(1));

    assert(playground::decimalToBinary(10) == "1010");
    assert(playground::decimalToOctal(10) == "12");
    assert(playground::decimalToHex(255) == "FF");

    assert(playground::isPalindrome(12321));
    assert(playground::isPalindrome("Never odd or even"));

    assert(playground::generateFibonacci(7) == std::vector<std::uint64_t>{0, 1, 1, 2, 3, 5, 8});
    assert(playground::calculateFactorial(5).value_or(0) == 120);

    auto addition = playground::calculate(4, '+', 6);
    assert(addition.success && addition.value == 10);

    auto divisionByZero = playground::calculate(4, '/', 0);
    assert(!divisionByZero.success);

    std::cout << "All tests passed.\n";
}
