#ifndef EXECUTOR_H
#define EXECUTOR_H

#include"table.h"
#include"query.h"

class Executor{
    public:
        Table execute(const Table& t, const Query& q);
    private:
        bool evaluateCondition(
            const std::vector<std::string>& row,
            const Table& table,
            const Condition& condition
        ) const;

        bool compare(
            const std::string& lhs,
            TokenType op,
            const Token& rhs
        ) const;
};
#endif