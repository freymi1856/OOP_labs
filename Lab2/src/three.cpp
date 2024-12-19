#pragma once
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <iostream>

class Three {
public:
    // Конструкторы
    Three();
    Three(size_t n, unsigned char t = 0);
    Three(const std::initializer_list<unsigned char>& t);
    Three(const std::string& t);
    Three(const Three& other);
    Three(Three&& other) noexcept;
    ~Three() noexcept;

    // Операторы
    Three& operator=(const Three& other);
    Three& operator=(Three&& other) noexcept;

    Three operator+(const Three& other) const;
    Three operator-(const Three& other) const;

    bool operator==(const Three& other) const;
    bool operator!=(const Three& other) const;
    bool operator<(const Three& other) const;
    bool operator<=(const Three& other) const;
    bool operator>(const Three& other) const;
    bool operator>=(const Three& other) const;

    // Методы
    size_t size() const;
    std::string toString() const;

private:
    std::vector<unsigned char> digits_; // Массив троичных цифр

    // Вспомогательные методы
    void validateDigits() const;
};

// Реализация

Three::Three() : digits_() {}

Three::Three(size_t n, unsigned char t) : digits_(n, t) {
    if (t > 2) {
        throw std::invalid_argument("Invalid trit value (must be 0, 1, or 2).");
    }
}

Three::Three(const std::initializer_list<unsigned char>& t) : digits_(t) {
    validateDigits();
}

Three::Three(const std::string& t) {
    for (char c : t) {
        if (c < '0' || c > '2') {
            throw std::invalid_argument("Invalid character in string (must be '0', '1', or '2').");
        }
        digits_.push_back(c - '0');
    }
}

Three::Three(const Three& other) : digits_(other.digits_) {}

Three::Three(Three&& other) noexcept : digits_(std::move(other.digits_)) {}

Three::~Three() noexcept {}

Three& Three::operator=(const Three& other) {
    if (this != &other) {
        digits_ = other.digits_;
    }
    return *this;
}

Three& Three::operator=(Three&& other) noexcept {
    if (this != &other) {
        digits_ = std::move(other.digits_);
    }
    return *this;
}

Three Three::operator+(const Three& other) const {
    size_t maxSize = std::max(digits_.size(), other.digits_.size());
    Three result(maxSize);
    unsigned char carry = 0;

    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char a = i < digits_.size() ? digits_[i] : 0;
        unsigned char b = i < other.digits_.size() ? other.digits_[i] : 0;
        unsigned char sum = a + b + carry;
        result.digits_[i] = sum % 3;
        carry = sum / 3;
    }

    if (carry) {
        result.digits_.push_back(carry);
    }

    return result;
}

Three Three::operator-(const Three& other) const {
    if (*this < other) {
        throw std::invalid_argument("Negative result in subtraction is not allowed for unsigned numbers.");
    }

    Three result(digits_.size());
    unsigned char borrow = 0;

    for (size_t i = 0; i < digits_.size(); ++i) {
        unsigned char a = digits_[i];
        unsigned char b = i < other.digits_.size() ? other.digits_[i] : 0;

        if (a < b + borrow) {
            result.digits_[i] = a + 3 - b - borrow;
            borrow = 1;
        } else {
            result.digits_[i] = a - b - borrow;
            borrow = 0;
        }
    }

    // Удаляем ведущие нули
    while (result.digits_.size() > 1 && result.digits_.back() == 0) {
        result.digits_.pop_back();
    }

    return result;
}

bool Three::operator==(const Three& other) const {
    return digits_ == other.digits_;
}

bool Three::operator!=(const Three& other) const {
    return !(*this == other);
}

bool Three::operator<(const Three& other) const {
    if (digits_.size() != other.digits_.size()) {
        return digits_.size() < other.digits_.size();
    }
    for (size_t i = digits_.size(); i-- > 0;) {
        if (digits_[i] != other.digits_[i]) {
            return digits_[i] < other.digits_[i];
        }
    }
    return false;
}

bool Three::operator<=(const Three& other) const {
    return *this < other || *this == other;
}

bool Three::operator>(const Three& other) const {
    return !(*this <= other);
}

bool Three::operator>=(const Three& other) const {
    return !(*this < other);
}

size_t Three::size() const {
    return digits_.size();
}

std::string Three::toString() const {
    std::string result;
    for (auto it = digits_.rbegin(); it != digits_.rend(); ++it) {
        result += std::to_string(*it);
    }
    return result;
}

void Three::validateDigits() const {
    for (unsigned char d : digits_) {
        if (d > 2) {
            throw std::invalid_argument("Invalid trit value (must be 0, 1, or 2).");
        }
    }
}