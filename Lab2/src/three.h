#ifndef THREE_H
#define THREE_H

#include <vector>
#include <string>
#include <stdexcept>

class Three {
private:
    std::vector<unsigned char> digits; // хранение цифр троичного числа

    // Проверяет корректность строки (должны быть только цифры 0, 1, 2)
    void validateString(const std::string& str);

public:
    // Конструкторы
    Three();
    Three(const std::string& number);

    // Арифметические операции
    Three operator+(const Three& other) const;
    Three operator-(const Three& other) const;

    // Операции сравнения
    bool operator==(const Three& other) const;
    bool operator!=(const Three& other) const;

    // Преобразование в строку
    std::string toString() const;
};

#endif