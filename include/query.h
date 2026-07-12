#ifndef QUERY_H
#define QUERY_H

#include<string>
#include<vector>

class query{

    public:
    void addSelectedColumn(const std::string& col);
    const std::vector<std::string>& getSelectedColumns() const;

    private:
    std::vector<std::string> selectedColumns;
};

#endif