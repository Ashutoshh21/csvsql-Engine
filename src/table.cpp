#include "table.h"
#include<stdexcept>

Table::Table(std::vector<std::string> header_,std::vector<std::vector<std::string>> rows_) : header(std::move(header_)),rows(std::move(rows_))
 //inner header -> constructor parameter 
{
    BuildColIndex();
}

void Table::BuildColIndex(){
    for(size_t i = 0; i < header.size(); i++){
        col_index_map[header[i]] = i;
    }
}

const std::vector<std::string>& Table::getheader() const{
    return header;
}

const std::vector<std::vector<std::string>>& Table::getrows() const{
    return rows;
}

size_t Table::col_count() const{
    return header.size();
}

size_t Table::rows_count() const{
    return rows.size();
}

size_t Table::columnIndex(const std::string& col) const{
    auto it = col_index_map.find(col);
    if(it == col_index_map.end()) throw std::runtime_error("Column not found " + col);
    return it->second;
}