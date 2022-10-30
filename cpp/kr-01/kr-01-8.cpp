#include <iostream>
#include <string>

std::string gen_power(uint32_t power) {
    if (!power) {
        return std::string(1, '1');
    } else {
        return std::string(power, 'x') + std::string(power - 1, '*');
    }
}
