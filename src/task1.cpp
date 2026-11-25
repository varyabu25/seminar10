#include "task1.h"
#include <istream>
#include <ostream>
#include <stdexcept>

namespace seminar10 {
std::stack<int> read_stack(std::istream& input) {
    long long count = 0;
    if (!(input >> count) || count < 0) throw std::invalid_argument("Количество элементов не может быть отрицательным.");
    std::stack<int> result;
    for (long long i = 0; i < count; ++i) {
        int value = 0;
        if (!(input >> value)) throw std::invalid_argument("Не удалось считать элемент стека.");
        result.push(value);
    }
    return result;
}

std::stack<int> reverse_stack(const std::stack<int>& input_stack) {
    std::stack<int> source = input_stack;
    std::stack<int> result;
    while (!source.empty()) {
        result.push(source.top());
        source.pop();
    }
    return result;
}

void print_stack(std::ostream& output, std::stack<int> stack) {
    if (stack.empty()) { output << "Стек пуст.\n"; return; }
    output << "Элементы от вершины к основанию: ";
    while (!stack.empty()) {
        output << stack.top();
        stack.pop();
        if (!stack.empty()) output << ' ';
    }
    output << '\n';
}
}
