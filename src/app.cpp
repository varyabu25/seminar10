#include "app.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include <iostream>
#include <limits>
#include <stdexcept>

namespace seminar10 {
namespace {
void clear_input_error() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int read_integer(const char* prompt) {
    int value = 0;
    std::cout << prompt;
    if (!(std::cin >> value)) {
        clear_input_error();
        throw std::invalid_argument("Ожидалось целое число.");
    }
    return value;
}

void run_stack_task() {
    std::cout << "\nВведите количество элементов: ";
    long long count = 0;
    if (!(std::cin >> count) || count < 0) {
        clear_input_error();
        throw std::invalid_argument("Количество элементов должно быть неотрицательным целым числом.");
    }
    std::cout << "Введите " << count << " элементов стека в одну строку через пробел: ";
    std::stack<int> input_stack;
    for (long long i = 0; i < count; ++i) {
        int val = 0;
        if (!(std::cin >> val)) {
            clear_input_error();
            throw std::invalid_argument("Не удалось считать элемент стека.");
        }
        input_stack.push(val);
    }

    const std::stack<int> output_stack = reverse_stack(input_stack);
    std::cout << "Входной ";
    print_stack(std::cout, input_stack);
    std::cout << "Выходной ";
    print_stack(std::cout, output_stack);
}

void run_priority_queue_task() {
    const int count = read_integer("\nВведите количество элементов очереди: ");
    if (count < 0) throw std::invalid_argument("Количество элементов не может быть отрицательным.");

    PriorityQueue queue;
    std::cout << "Вводите элементы в формате: <значение> <приоритет> (через пробел, каждый с новой строки):\n";
    for (int i = 0; i < count; ++i) {
        const int value = read_integer("  Значение: ");
        const int priority = read_integer("  Приоритет (меньше число — выше приоритет): ");
        queue.push(value, priority);
    }

    std::cout << "Порядок извлечения элементов:\n";
    while (!queue.empty()) {
        const auto element = queue.pop();
        std::cout << "  Значение: " << element->value
                  << ", приоритет: " << element->priority << '\n';
    }
}

void run_deque_task() {
    std::cout << "\nВведите количество начальных элементов дека: ";
    long long count = 0;
    if (!(std::cin >> count) || count < 0) {
        clear_input_error();
        throw std::invalid_argument("Количество элементов должно быть неотрицательным целым числом.");
    }
    std::cout << "Введите " << count << " элементов дека в одну строку через пробел: ";
    std::deque<int> values;
    for (long long i = 0; i < count; ++i) {
        int val = 0;
        if (!(std::cin >> val)) {
            clear_input_error();
            throw std::invalid_argument("Не удалось считать элемент дека.");
        }
        values.push_back(val);
    }

    bool running = true;
    while (running) {
        std::cout << "\nТекущий ";
        print_deque(std::cout, values);
        std::cout << "1 — добавить в начало\n"
                  << "2 — добавить в конец\n"
                  << "3 — удалить из начала\n"
                  << "4 — удалить из конца\n"
                  << "0 — вернуться в главное меню\n";

        const int choice = read_integer("Выберите операцию: ");
        switch (choice) {
            case 1:
                push_front(values, read_integer("Введите значение: "));
                break;
            case 2:
                push_back(values, read_integer("Введите значение: "));
                break;
            case 3: {
                const auto removed = pop_front(values);
                if (removed.has_value()) std::cout << "Удалён элемент: " << *removed << '\n';
                else std::cout << "Дек пуст, удаление невозможно.\n";
                break;
            }
            case 4: {
                const auto removed = pop_back(values);
                if (removed.has_value()) std::cout << "Удалён элемент: " << *removed << '\n';
                else std::cout << "Дек пуст, удаление невозможно.\n";
                break;
            }
            case 0:
                running = false;
                break;
            default:
                std::cout << "Неизвестная операция.\n";
                break;
        }
    }
}
}

void run_menu() {
    bool running = true;
    while (running) {
        std::cout << "\n========== СЕМИНАР 10 ==========\n"
                  << "1 — Обратный порядок стека\n"
                  << "2 — Очередь с приоритетом\n"
                  << "3 — Дек\n"
                  << "0 — Выход\n";

        try {
            const int choice = read_integer("Выберите задание: ");
            switch (choice) {
                case 1: run_stack_task(); break;
                case 2: run_priority_queue_task(); break;
                case 3: run_deque_task(); break;
                case 0: running = false; break;
                default: std::cout << "Такого пункта меню нет.\n"; break;
            }
        } catch (const std::invalid_argument& error) {
            std::cout << "Ошибка ввода: " << error.what() << '\n';
        }
    }
}
}
