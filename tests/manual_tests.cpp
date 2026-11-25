#include "task1.h"
#include "task2.h"
#include "task3.h"
#include <cassert>
#include <sstream>
#include <stack>
int main() {
    std::istringstream stack_input("3 1 2 3");
    const std::stack<int> source = seminar10::read_stack(stack_input);
    std::stack<int> reversed = seminar10::reverse_stack(source);
    assert(reversed.top() == 1); reversed.pop();
    assert(reversed.top() == 2); reversed.pop();
    assert(reversed.top() == 3);

    const std::stack<int> empty_stack;
    assert(seminar10::reverse_stack(empty_stack).empty());

    seminar10::PriorityQueue queue;
    queue.push(100, 2); queue.push(200, 1); queue.push(300, 1);
    assert(queue.pop()->value == 200);
    assert(queue.pop()->value == 300);
    assert(queue.pop()->value == 100);
    assert(queue.empty());

    std::deque<int> values;
    seminar10::push_back(values, 2);
    seminar10::push_front(values, 1);
    seminar10::push_back(values, 3);
    assert(seminar10::pop_front(values) == 1);
    assert(seminar10::pop_back(values) == 3);
    assert(seminar10::pop_front(values) == 2);

    seminar10::PriorityQueue empty_queue;
    assert(!empty_queue.top().has_value());
    assert(!empty_queue.pop().has_value());
    assert(!seminar10::pop_front(values).has_value());
    assert(!seminar10::pop_back(values).has_value());
    return 0;
}
