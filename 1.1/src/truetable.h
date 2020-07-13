#ifndef TRUETABLE_H
#define TRUETABLE_H

#include"truetable_headers.h"

class true_table
{
private:
    std::vector<Proposition>variable;
    std::stack<char>s;
    std::string expression;
public:
    true_table() {};
    true_table(const Proposition& var) { this->variable.push_back(var); }
    true_table(const std::string& x) :expression(x) {}

    void add(const Proposition& var) { this->variable.push_back(var); }

    std::string transform(const std::string& infix_expression);
    bool result(const std::string& suffix_expression);

    void show_true_table() const;
};

#endif