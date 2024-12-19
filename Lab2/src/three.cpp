#include "three.h"
#include <algorithm>
#include <stdexcept>

// Конструкторы
Three::Three() : digits(1, 0) {}

Three::Three(const std::string& num_str) {
    for (char c : num_str) {
        if (c < '0' || c > '2') {
            throw std::invalid_argument("Invalid character in ternary number string.");
        }
        digits.push_back(c - '0');
    }
    std::reverse(digits.begin(), digits.end());
}

// Методы
std::string Three::toString() const {
    std::string result;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        result += std::to_string(*it);
    }
    return result;
}

// Операторы сравнения
bool Three::operator==(const Three& other) const {
    return digits == other.digits;
}

bool Three::operator!=(const Three& other) const {
    return !(*this == other);
}

bool Three::operator<(const Three& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;
}

bool Three::operator>(const Three& other) const {
    return other < *this;
}

bool Three::operator<=(const Three& other) const {
    return !(other < *this);
}

bool Three::operator>=(const Three& other) const {
    return !(*this < other);
}

// Оператор присваивания
Three& Three::operator=(const Three& other) {
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}

// Арифметические операторы
Three Three::operator+(const Three& other) const {
    std::vector<unsigned char> result;
    size_t max_size = std::max(digits.size(), other.digits.size());
    unsigned char carry = 0;

    for (size_t i = 0; i < max_size || carry; ++i) {
        unsigned char sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];

        result.push_back(sum % 3);
        carry = sum / 3;
    }

    return Three(result);
}

Three Three::operator-(const Three& other) const {
    if (*this < other) {
        throw std::out_of_range("Result of subtraction cannot be negative in ternary numbers.");
    }

    std::vector<unsigned char> result;
    unsigned char borrow = 0;

    for (size_t i = 0; i < digits.size(); ++i) {
        int sub = digits[i] - borrow;
        if (i < other.digits.size()) {
            sub -= other.digits[i];
        }

        if (sub < 0) {
            sub += 3;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_back(static_cast<unsigned char>(sub));
    }

    // Удаление ведущих нулей
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return Three(result);
}

// Вспомогательный конструктор
Three::Three(const std::vector<unsigned char>& digits) : digits(digits) {}