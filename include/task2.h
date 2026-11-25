#pragma once
#include <cstddef>
#include <optional>
#include <queue>
#include <vector>
namespace seminar10 {
struct PriorityElement {
    int value;
    int priority;
    std::size_t order;
};
class PriorityQueue {
public:
    void push(int value, int priority);
    std::optional<PriorityElement> top() const;
    std::optional<PriorityElement> pop();
    bool empty() const;
    std::size_t size() const;
private:
    struct Compare {
        bool operator()(const PriorityElement& left, const PriorityElement& right) const;
    };
    std::priority_queue<PriorityElement, std::vector<PriorityElement>, Compare> elements_;
    std::size_t next_order_ = 0;
};
}
