#include"query.h"

//setters
void Query::addSelectedColumn(const std::string& col){
    selectedColumns.push_back(col);
}

void Query::setWhereCondition(const Condition& condition){
    whereCondition= condition;
}

//getters
const std::vector<std::string>& Query::getSelectedColumns() const{
    return selectedColumns;
}
const std::optional<Condition>& Query::getWhereCondition() const{
    return whereCondition;
}