#pragma once
#include <deque>
#include <iosfwd>
#include <optional>
namespace seminar10 {
std::deque<int> read_deque(std::istream& input);
void push_front(std::deque<int>& values, int value);
void push_back(std::deque<int>& values, int value);
std::optional<int> pop_front(std::deque<int>& values);
std::optional<int> pop_back(std::deque<int>& values);
void print_deque(std::ostream& output, const std::deque<int>& values);
}
