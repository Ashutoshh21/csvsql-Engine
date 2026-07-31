#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <vector>
#include <optional>

#include "tokenizer.h"

class Condition {
public:
    std::string column;
    TokenType op;
    Token value;
};

class Query {
public:
    //setters
    void addSelectedColumn(const std::string& col);
    void setWhereCondition(const Condition& condition);

    //getters
    const std::vector<std::string>& getSelectedColumns() const;
    const std::optional<Condition>& getWhereCondition() const;

private:
    std::vector<std::string> selectedColumns;
    std::optional<Condition> whereCondition;
};

#endif