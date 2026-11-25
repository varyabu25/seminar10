#pragma once
#include <iosfwd>
#include <stack>
namespace seminar10 {
std::stack<int> read_stack(std::istream& input);
std::stack<int> reverse_stack(const std::stack<int>& input_stack);
void print_stack(std::ostream& output, std::stack<int> stack);
}
