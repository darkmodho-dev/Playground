#ifndef PLAYGROUND_EXERCISES_HPP
#define PLAYGROUND_EXERCISES_HPP

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace playground {

bool isPrime(std::uint64_t value);
std::vector<std::uint64_t> generatePrimes(std::uint64_t limit);
std::vector<std::uint64_t> generateEvenNumbers(std::uint64_t limit);
std::vector<std::uint64_t> generateOddNumbers(std::uint64_t limit);
std::vector<std::uint64_t> generateFibonacci(std::size_t terms);
std::optional<std::uint64_t> calculateFactorial(std::uint32_t value);
bool isPalindrome(std::uint64_t value);
bool isPalindrome(const std::string& value);
std::string decimalToBinary(std::uint64_t value);
std::string decimalToOctal(std::uint64_t value);
std::string decimalToHex(std::uint64_t value);
std::uint64_t generateRandomNumber(std::uint64_t minimum, std::uint64_t maximum);

struct CalculatorResult {
    bool success;
    long double value;
};

CalculatorResult calculate(long double left, char operation, long double right);

} // namespace playground

#endif
