#ifndef THREE_H
#define THREE_H

#include <string>
#include <vector>

class Three {
public:
    // Конструкторы
    Three(); // Конструктор по умолчанию
    explicit Three(const std::string& num_str); // Из строки

    // Методы
    std::string toString() const;

    // Операторы сравнения
    bool operator==(const Three& other) const;
    bool operator!=(const Three& other) const;
    bool operator<(const Three& other) const;
    bool operator<=(const Three& other) const;
    bool operator>(const Three& other) const;
    bool operator>=(const Three& other) const;

    // Оператор присваивания
    Three& operator=(const Three& other);

    // Арифметические операторы
    Three operator+(const Three& other) const;
    Three operator-(const Three& other) const;

private:
    // Вспомогательный конструктор
    explicit Three(const std::vector<unsigned char>& digits);

    std::vector<unsigned char> digits; // Вектор троичных цифр
};

#endif