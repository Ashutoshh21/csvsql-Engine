#include"executor.h"

Table Executor::execute(const Table& t, const Query& q){

    //collecting the projecting columns indices at once
    std::vector<size_t> colIndices;
    const auto& selectedCols = q.getSelectedColumns();
    for(const auto& col : selectedCols){
        colIndices.push_back(t.columnIndex(col));
    }

    //getting parent table rows and cols
    const auto& header = t.getheader(); //can also write auto& and it'll fetch const too since it's the return type of that func
    const auto& rows = t.getrows();

    
    //to store our projected table rows and cols
    std::vector<std::string> new_head;
    size_t num_rows = t.rows_count();
    std::vector<std::vector<std::string>> new_rows;

    // new-header building
    for(const auto& id : colIndices){
        new_head.push_back(header[id]);
    }

    //our table's row-building
    for(size_t i = 0; i < num_rows; i++){
        if (q.getWhereCondition().has_value()) {
            if (!evaluateCondition(rows[i], t, q.getWhereCondition().value()))
                continue;
        }
        std::vector<std::string> new_row;
        for(const auto& id : colIndices){
            new_row.push_back(rows[i][id]);
        }
        new_rows.push_back(std::move(new_row)); //since new_row won't be used again, let's not copy it totally, and just move it into new_rows
    }

    return Table(new_head, new_rows);
}

bool Executor::evaluateCondition(const std::vector<std::string>& row, const Table& table, const Condition& condition) const{
    size_t index = table.columnIndex(condition.column);
    return compare(row[index], condition.op, condition.value);
} 

bool Executor::compare(const std::string& col, TokenType op, const Token& value) const{
    if(value.type == TokenType::NUMBER){
        int lhs;
        try {
            lhs = std::stoi(col);
        }
        catch (...) {
            throw std::runtime_error(
                "Expected numeric data but Found '" +
                col + "'");
        }
        int rhs = std::stoi(value.lexeme);
        switch(op){
            case TokenType::GREATER: return lhs > rhs;
            case TokenType::GREATER_EQUAL: return lhs >= rhs;
            case TokenType::LESS: return lhs < rhs;
            case TokenType::LESS_EQUAL: return lhs <= rhs;
            case TokenType::EQUAL: return lhs == rhs;
            case TokenType::NOT_EQUAL: return lhs != rhs;
            default: throw std::runtime_error("Invalid Operator");
        }
    }
    else{
        switch(op)
        {
        case TokenType::EQUAL:
            return col == value.lexeme;

        case TokenType::NOT_EQUAL:
            return col != value.lexeme;

        default:
            throw std::runtime_error(
                "Only '=' and '!=' are allowed for string comparisons");
        }
    }
}