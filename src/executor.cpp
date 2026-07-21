#include"executor.h"

Table Executor::execute(const Table& t, const Query& q){
    std::vector<size_t> colIndices;
    const auto& selectedCols = q.getSelectedColumns();
    for(auto col : selectedCols){
        colIndices.push_back(t.columnIndex(col));
    }
    const auto& header = t.getheader(); //can also write auto& and it'll fetch const too since it's the return type of that func
    const auto& rows = t.getrows();

    std::vector<std::string> new_head;
    size_t num_rows = t.rows_count();
    std::vector<std::vector<std::string>> new_rows(num_rows);
    for(auto id : colIndices){
        new_head.push_back(header[id]);
    }
    for(int i = 0; i < num_rows; i++){
        for(auto id : colIndices){
            new_rows[i].push_back(rows[i][id]);
        }
    }

    return Table(new_head, new_rows);
}