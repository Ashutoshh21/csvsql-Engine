#include"query.h"

void Query::addSelectedColumn(const std::string& col){
    selectedColumns.push_back(col);
}

const std::vector<std::string>& Query::getSelectedColumns() const{
    return selectedColumns;
}