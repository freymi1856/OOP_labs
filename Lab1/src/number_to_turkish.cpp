#include "number_to_turkish.h"
#include <stdexcept>

std::string NumberToTurkish(int number) {
    const std::string units[] = {"sıfır", "bir", "iki", "üç", "dört", "beş", "altı", "yedi", "sekiz", "dokuz"};
    const std::string tens[] = {"", "on", "yirmi", "otuz", "kırk", "elli", "altmış", "yetmiş", "seksen", "doksan"};

    if (number < 0 || number > 99) {
        throw std::out_of_range("Number must be between 0 and 99.");
    }

    int ten = number / 10;
    int unit = number % 10;

    if (ten == 0) {
        return units[unit];
    }
    if (unit == 0) {
        return tens[ten];
    }
    return tens[ten] + " " + units[unit];
}