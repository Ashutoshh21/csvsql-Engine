#include"query.h"

void query::addSelectedColumn(const std::string& col){
    selectedColumns.push_back(col);
}

const std::vector<std::string>& query::getSelectedColumns() const{
    return selectedColumns;
}