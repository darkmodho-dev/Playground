#include "playground/exercises.hpp"

#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

namespace {

void printLine() {
    std::cout << "----------------------------------------\n";
}

int readMenuChoice() {
    int choice;
    while (!(std::cin >> choice) || choice < 1 || choice > 11) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Enter a number from 1 to 11: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

std::uint64_t readUnsigned(const std::string& prompt) {
    std::uint64_t value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a non-negative number.\n";
    }
}

void printNumbers(const std::vector<std::uint64_t>& numbers) {
    for (std::size_t index = 0; index < numbers.size(); ++index) {
        if (index != 0) std::cout << ' ';
        std::cout << numbers[index];
    }
    std::cout << '\n';
}

} // namespace

int main() {
    std::cout << "C++ Playground\n";

    while (true) {
        printLine();
        std::cout
            << "1. Prime number checker\n"
            << "2. Prime number generator\n"
            << "3. Even numbers\n"
            << "4. Odd numbers\n"
            << "5. Fibonacci sequence\n"
            << "6. Factorial calculator\n"
            << "7. Palindrome checker\n"
            << "8. Number converter\n"
            << "9. Random number generator\n"
            << "10. Basic calculator\n"
            << "11. Exit\n"
            << "Choose an option: ";

        switch (readMenuChoice()) {
            case 1: {
                auto value = readUnsigned("Enter a number: ");
                std::cout << value << (playground::isPrime(value) ? " is prime.\n" : " is not prime.\n");
                break;
            }
            case 2: {
                auto limit = readUnsigned("Enter the upper limit: ");
                printNumbers(playground::generatePrimes(limit));
                break;
            }
            case 3: {
                auto limit = readUnsigned("Enter the upper limit: ");
                printNumbers(playground::generateEvenNumbers(limit));
                break;
            }
            case 4: {
                auto limit = readUnsigned("Enter the upper limit: ");
                printNumbers(playground::generateOddNumbers(limit));
                break;
            }
            case 5: {
                auto terms = readUnsigned("Enter the number of terms: ");
                try {
                    printNumbers(playground::generateFibonacci(static_cast<std::size_t>(terms)));
                } catch (const std::overflow_error& error) {
                    std::cout << "Error: " << error.what() << '\n';
                }
                break;
            }
            case 6: {
                auto value = readUnsigned("Enter a number (0-20): ");
                if (value > 20) {
                    std::cout << "Error: factorial is only supported from 0 to 20.\n";
                } else {
                    auto result = playground::calculateFactorial(static_cast<std::uint32_t>(value));
                    std::cout << value << "! = " << *result << '\n';
                }
                break;
            }
            case 7: {
                std::cout << "Enter text or a number: ";
                std::string value;
                std::getline(std::cin, value);
                std::cout << (playground::isPalindrome(value) ? "It is a palindrome.\n" : "It is not a palindrome.\n");
                break;
            }
            case 8: {
                auto value = readUnsigned("Enter a decimal number: ");
                std::cout << "Binary: " << playground::decimalToBinary(value) << '\n'
                          << "Octal: " << playground::decimalToOctal(value) << '\n'
                          << "Hexadecimal: " << playground::decimalToHex(value) << '\n';
                break;
            }
            case 9: {
                auto minimum = readUnsigned("Enter the minimum: ");
                auto maximum = readUnsigned("Enter the maximum: ");
                if (minimum > maximum) {
                    std::cout << "Error: minimum cannot exceed maximum.\n";
                } else {
                    std::cout << "Random value: "
                              << playground::generateRandomNumber(minimum, maximum) << '\n';
                }
                break;
            }
            case 10: {
                long double left;
                char operation;
                long double right;
                std::cout << "Enter expression (for example: 12 * 3): ";
                if (std::cin >> left >> operation >> right) {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    auto result = playground::calculate(left, operation, right);
                    if (!result.success) {
                        std::cout << "Error: invalid operation or division by zero.\n";
                    } else {
                        std::cout << std::setprecision(15) << "Result: " << result.value << '\n';
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid expression.\n";
                }
                break;
            }
            case 11:
                std::cout << "Goodbye!\n";
                return 0;
        }
    }
}
