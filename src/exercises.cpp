#include "playground/exercises.hpp"

#include <algorithm>
#include <cmath>
#include <limits>
#include <random>
#include <sstream>
#include <stdexcept>

namespace playground {

bool isPrime(std::uint64_t value) {
    if (value < 2) return false;
    if (value == 2) return true;
    if (value % 2 == 0) return false;

    for (std::uint64_t divisor = 3; divisor <= value / divisor; divisor += 2) {
        if (value % divisor == 0) return false;
    }
    return true;
}

std::vector<std::uint64_t> generatePrimes(std::uint64_t limit) {
    std::vector<std::uint64_t> result;
    for (std::uint64_t value = 2; value <= limit; ++value) {
        if (isPrime(value)) result.push_back(value);
    }
    return result;
}

std::vector<std::uint64_t> generateEvenNumbers(std::uint64_t limit) {
    std::vector<std::uint64_t> result;
    for (std::uint64_t value = 0; value <= limit; ++value) {
        if (value % 2 == 0) result.push_back(value);
    }
    return result;
}

std::vector<std::uint64_t> generateOddNumbers(std::uint64_t limit) {
    std::vector<std::uint64_t> result;
    for (std::uint64_t value = 1; value <= limit; ++value) {
        if (value % 2 != 0) result.push_back(value);
    }
    return result;
}

std::vector<std::uint64_t> generateFibonacci(std::size_t terms) {
    std::vector<std::uint64_t> result;
    std::uint64_t first = 0;
    std::uint64_t second = 1;

    for (std::size_t index = 0; index < terms; ++index) {
        result.push_back(first);
        if (index + 1 == terms) break;

        std::uint64_t next = first + second;
        if (next < first) {
            throw std::overflow_error("Fibonacci sequence overflow");
        }
        first = second;
        second = next;
    }
    return result;
}

std::optional<std::uint64_t> calculateFactorial(std::uint32_t value) {
    if (value > 20) return std::nullopt;

    std::uint64_t result = 1;
    for (std::uint32_t number = 2; number <= value; ++number) {
        result *= number;
    }
    return result;
}

bool isPalindrome(std::uint64_t value) {
    return isPalindrome(std::to_string(value));
}

bool isPalindrome(const std::string& value) {
    std::string cleaned;
    cleaned.reserve(value.size());
    for (char character : value) {
        if (std::isalnum(static_cast<unsigned char>(character))) {
            cleaned.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(character))));
        }
    }
    return std::equal(cleaned.begin(), cleaned.begin() + cleaned.size() / 2, cleaned.rbegin());
}

std::string decimalToBinary(std::uint64_t value) {
    if (value == 0) return "0";
    std::string result;
    while (value > 0) {
        result.push_back(static_cast<char>('0' + (value % 2)));
        value /= 2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string decimalToOctal(std::uint64_t value) {
    if (value == 0) return "0";
    std::string result;
    while (value > 0) {
        result.push_back(static_cast<char>('0' + (value % 8)));
        value /= 8;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string decimalToHex(std::uint64_t value) {
    if (value == 0) return "0";
    constexpr char digits[] = "0123456789ABCDEF";
    std::string result;
    while (value > 0) {
        result.push_back(digits[value % 16]);
        value /= 16;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::uint64_t generateRandomNumber(std::uint64_t minimum, std::uint64_t maximum) {
    if (minimum > maximum) throw std::invalid_argument("Minimum cannot exceed maximum");

    static std::random_device randomDevice;
    static std::mt19937_64 generator(randomDevice());
    std::uniform_int_distribution<std::uint64_t> distribution(minimum, maximum);
    return distribution(generator);
}

CalculatorResult calculate(long double left, char operation, long double right) {
    switch (operation) {
        case '+': return {true, left + right};
        case '-': return {true, left - right};
        case '*': return {true, left * right};
        case '/':
            if (right == 0.0L) return {false, 0.0L};
            return {true, left / right};
        default: return {false, 0.0L};
    }
}

} // namespace playground
