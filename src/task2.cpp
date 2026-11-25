#include "task2.h"
namespace seminar10 {
bool PriorityQueue::Compare::operator()(const PriorityElement& left, const PriorityElement& right) const {
    if (left.priority != right.priority) return left.priority > right.priority;
    return left.order > right.order;
}
void PriorityQueue::push(int value, int priority) {
    elements_.push(PriorityElement{value, priority, next_order_});
    ++next_order_;
}
std::optional<PriorityElement> PriorityQueue::top() const {
    if (elements_.empty()) return std::nullopt;
    return elements_.top();
}
std::optional<PriorityElement> PriorityQueue::pop() {
    if (elements_.empty()) return std::nullopt;
    const PriorityElement result = elements_.top();
    elements_.pop();
    return result;
}
bool PriorityQueue::empty() const { return elements_.empty(); }
std::size_t PriorityQueue::size() const { return elements_.size(); }
}
