#include "task3.h"
#include <istream>
#include <ostream>
#include <stdexcept>

namespace seminar10 {
std::deque<int> read_deque(std::istream& input) {
    long long count = 0;
    if (!(input >> count) || count < 0) throw std::invalid_argument("Количество элементов не может быть отрицательным.");
    std::deque<int> result;
    for (long long i = 0; i < count; ++i) {
        int value = 0;
        if (!(input >> value)) throw std::invalid_argument("Не удалось считать элемент дека.");
        result.push_back(value);
    }
    return result;
}

void push_front(std::deque<int>& values, int value) { values.push_front(value); }
void push_back(std::deque<int>& values, int value) { values.push_back(value); }

std::optional<int> pop_front(std::deque<int>& values) {
    if (values.empty()) return std::nullopt;
    const int result = values.front();
    values.pop_front();
    return result;
}

std::optional<int> pop_back(std::deque<int>& values) {
    if (values.empty()) return std::nullopt;
    const int result = values.back();
    values.pop_back();
    return result;
}

void print_deque(std::ostream& output, const std::deque<int>& values) {
    if (values.empty()) { output << "Дек пуст.\n"; return; }
    output << "Элементы дека: ";
    for (std::size_t i = 0; i < values.size(); ++i) {
        output << values[i];
        if (i + 1 < values.size()) output << ' ';
    }
    output << '\n';
}
}
